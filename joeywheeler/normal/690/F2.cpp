#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

const int NMOD = 2;
const int MOD[NMOD] = {1000000007, 1000000009};
//const int BASE[NMOD] = {137, 139};

struct hs {
    int hv[NMOD];
    int lp[NMOD];

    hs() {
        FO(i,0,NMOD) hv[i] = 0, lp[i] = 1;
    }

    bool operator<(const hs &o) const {
        FO(i,0,NMOD) if (hv[i] != o.hv[i]) return hv[i] < o.hv[i];
        return false;
    }

    bool operator==(const hs &o) const {
        FO(i,0,NMOD) if (hv[i] != o.hv[i]) return false;
        return true;
    }

    bool operator!=(const hs &o) const {
        return !(*this == o);
    }
};

hs nd;
hs delim1;
hs delim2;

hs mrg(hs a, hs b) {
    FO(i,0,NMOD) {
        a.hv[i] = (a.hv[i] * 1ll * b.lp[i] + b.hv[i]) % MOD[i];
        a.lp[i] = a.lp[i] * 1ll * b.lp[i] % MOD[i];
    }
    return a;
}

struct HTREE {
    int n;
    vector<int> u[1005];
    map<int,hs> cache[1005];

    int l[1005];
    set<hs> hshs;

    int gl(int i) {
        return i == l[i] ? i : l[i] = gl(l[i]);
    }

    void init(int _n) {
        n = _n;
        FO(i,0,n) cache[i].clear(), u[i].clear();
        FO(i,0,n) l[i] = i;
        hshs.clear();
    }

    void adde(int i, int j) {
        u[i].push_back(j);
        u[j].push_back(i);
        l[gl(i)] = gl(j);
    }

    hs dp(int i, int j) {
        // hash i->j == the rooted tree at j (cutting i-j)
        if (cache[i].count(j)) return cache[i][j];
        vector<hs> v;
        for (int k : u[j]) if (k != i) {
            v.push_back(dp(j,k));
        }
        sort(v.begin(),v.end());
        hs res = delim1;
        for (auto h : v) {
            res = mrg(res, h);
        }
        res = mrg(res, delim2);
        cache[i][j] = res;
        return cache[i][j];
    }

    void proc() {
        FO(i,0,n) cache[i].clear();
        hshs.clear();
        FO(i,0,n) {
            vector<hs> v;
            for (int j : u[i]) if (j != i) {
                v.push_back(dp(i,j));
            }
            sort(v.begin(),v.end());
            hs res = delim1;
            for (auto h : v) {
                res = mrg(res, h);
            }
            res = mrg(res, delim2);
            hshs.insert(res);
        }
    }
};

HTREE ht[105];

int cnt[105];

int main() {
    FO(i,0,2) nd.hv[i] = 1, nd.lp[i] = 137;
    FO(i,0,2) delim1.hv[i] = 2, delim1.lp[i] = 137;
    FO(i,0,2) delim2.hv[i] = 3, delim2.lp[i] = 137;

    int T; scanf("%d", &T);
    FO(_,0,T) {
        int n, k;
        scanf("%d %d", &n, &k);

        int sp = -1, spi = -1;
        FO(i,0,k) {
            int m; scanf("%d", &m);
            ht[i].init(n);
            FO(j,0,m) {
                int x, y; scanf("%d %d", &x, &y); x--; y--;
                ht[i].adde(x,y);
            }
            FO(j,0,n) cnt[j] = 0;
            FO(j,0,n) cnt[ht[i].gl(j)]++;
            set<int> lds;
            FO(j,0,n) lds.insert(ht[i].gl(j));
            if (sz(lds) == 2) {
                FO(j,0,n) {
                    if (cnt[j] == 1) {
                        //printf("i=%d is spec\n", i);
                        sp = i;
                        spi = j;
                    }
                }
            }
        }
        assert(sp != -1);
        //printf("sp = %d\n", sp);
        //printf("spi = %d\n", spi);
        swap(ht[sp],ht[0]);

        FO(i,0,k) ht[i].proc();

        FO(z,0,n) if (z != spi) {
            HTREE cnd = ht[0];
            cnd.adde(z, spi);
            cnd.proc();

            set<int> rem;
            FO(i,0,k) rem.insert(i);
            FO(i,0,n) {
                int brm = -1;
                for (int x : rem) {
                    // does del i look like ht[x]
                    for (int j : cnd.u[i]) {
                        if (!ht[x].hshs.count(cnd.dp(i,j))) {
                            goto notfound;
                        }
                    }
                    brm = x;
notfound:;
                }
                //printf("COULDN'T GET %d\n", i);
                if (brm == -1) {
                    goto notgoodcand;
                } else {
                    //printf("%d : %d\n", i, brm);
                    rem.erase(brm);
                }
            }

            printf("YES\n");
            FO(i,0,n) for (int j : cnd.u[i]) if (i < j) {
                printf("%d %d\n", i+1, j+1);
            }
            goto foundans;
notgoodcand:;
        }
        printf("NO\n");
foundans:;
    }
}