#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007

using namespace std;

struct EBM {
    tuple<int,int,int> e[55];
    int ne;
    int fc[1<<20], fn[1<<20];
    int rs[55];

    void clear() { ne = 0; }

    void adde(int x, int y, int w) {
        e[ne++] = make_tuple(x,y,(MOD+w-1)%MOD);
    }

    void clc(int nb) {
        sort(e,e+ne);
        FO(i,0,1<<nb) fc[i] = 0;
        fc[0] = 1;
        int pu = -1;
        for (int i = ne-1; i >= 0; i--) {
            int u, v; long long w; tie(u,v,w) = e[i];
            if (u != pu) FO(j,0,1<<nb) fn[j] = fc[j];
            FO(j,0,1<<nb) if (j&(1<<v)) fc[j] = (fc[j] + w * fn[j ^ (1<<v)]) % MOD;
            pu = u;
        }
        FO(i,0,55) rs[i] = 0;
        FO(i,0,1<<nb) {
            int m = __builtin_popcount(i);
            rs[m] += fc[i];
            if (rs[m] >= MOD) rs[m] -= MOD;
        }
    }
} ebm;

struct ETM {
    multiset<pair<int,int> > u[55];
    tuple<int,int,int> aux[55]; int na;
    bool seen[55];
    int rs[55];

    void clear() {
        FO(i,0,55) u[i].clear();
        na = 0;
        FO(i,0,55) seen[i] = false;
        FO(i,0,55) rs[i] = 0;
    }

    void adde(int x, int y, int w) {
        u[x].emplace(y,(w+MOD-1)%MOD);
        u[y].emplace(x,(w+MOD-1)%MOD);
    }

    void go(int i) {
        seen[i] = true;
        for (auto e : u[i]) {
            int j, w; tie(j,w) = e;
            if (!seen[j]) {
                u[j].erase(u[j].find(make_pair(i,w)));
                go(j);
            } else if (i < j) aux[na++] = make_tuple(i,j,w);
        }
    }

    int c[55][55][55][2];

    long long f(int i, int j, int t, bool tk) {
        if (seen[i] && tk) return 0;
        auto it = u[i].upper_bound(make_pair(j,MOD));
        if (it == u[i].end()) return t == 0;
        if (c[i][j+1][t][tk] != -1) return c[i][j+1][t][tk];

        int nj, w; tie(nj,w) = *it;
        long long res = 0;
        if (!tk) FO(tt,0,t) res += w * f(nj, -1, tt, true) % MOD * f(i, nj, t-tt-1, true) % MOD;
        FO(tt,0,t+1) res += f(nj, -1, tt, false) * f(i, nj, t-tt, tk) % MOD;

        return c[i][j+1][t][tk] = res % MOD;
    }

    void clc(int n) {
        go(0);
        FO(e,0,na) {
            int i, j, w; tie(i,j,w) = aux[e];
            u[i].erase(u[i].find(make_pair(j,w)));
            u[j].erase(u[j].find(make_pair(i,w)));
        }
        FO(i,0,1<<na) {
            FO(j,0,n) seen[j] = false;
            int ne = __builtin_popcount(i);
            long long p = 1;
            FO(j,0,na) if (i&(1<<j)) {
                int x,y,w; tie(x,y,w) = aux[j];
                p = p * w % MOD;
                if (seen[x] || seen[y]) {
                    ne = -1;
                    break;
                }
                seen[x] = seen[y] = true;
            }
            if (ne == -1) continue;
            memset(c,-1,sizeof c);
            FO(j,ne,55) rs[j] = (rs[j] + f(0,-1,j-ne,false) * p) % MOD;
        }
    }
} etm;

int n, k;
int x[2][55], w[55];
bool sn[2][100005];
vector<int> v[2];
int c[2][100005], cv;
long long rs[55];
long long trs[55];

void go(int i, int j) {
    if (sn[j][i]) return;
    sn[j][i] = true;
    v[j].push_back(i);
    FO(e,0,k) if (x[j][e] == i) go(x[!j][e], !j);
}

void mrg(int *nrs) {
    FO(j,0,55) trs[j] = 0;
    FO(s,0,55) FO(j,0,55) if (rs[s] && nrs[j]) trs[s+j] = (trs[s+j] + rs[s] * nrs[j]) % MOD;
    FO(j,0,55) rs[j] = trs[j];
}

int main() {
    memset(c,-1,sizeof c);
    scanf("%d %d", &n, &k);
    FO(i,0,k) scanf("%d %d %d", x[0]+i, x[1]+i, w+i);
    rs[0] = 1;
    FO(i,0,k) if (!sn[0][x[0][i]]) {
        go(x[0][i],0);

        int nv[2] = {};
        FO(j,0,2) for (int t : v[j]) c[j][t] = nv[j]++;
        if (min(nv[0],nv[1]) <= 20) {
            ebm.clear();
            FO(j,0,k) if (c[0][x[0][j]] != -1) {
                int u0 = c[0][x[0][j]], u1 = c[1][x[1][j]];
                if (nv[0] > nv[1]) ebm.adde(u0, u1, w[j]);
                else ebm.adde(u1, u0, w[j]);
            }
            ebm.clc(min(nv[0],nv[1]));
            mrg(ebm.rs);
        } else {
            etm.clear();
            FO(j,0,k) if (c[0][x[0][j]] != -1) {
                int u0 = c[0][x[0][j]], u1 = c[1][x[1][j]];
                etm.adde(u0, nv[0]+u1, w[j]);
            }
            etm.clc(nv[0]+nv[1]);
            mrg(etm.rs);
        }

        FO(j,0,2) for (int t : v[j]) c[j][t] = -1;
        FO(j,0,2) v[j].clear();
    }
    int cfn = 0;
    long long cf = 1, ans = 0;
    for (int i = 54; i >= 0; i--) if (rs[i]) {
        while (cfn < n-i) cf = cf * ++cfn % MOD;
        ans = (ans + cf * rs[i]) % MOD;
    }
    printf("%lld\n", ans);
}