#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int n, m;
char s[100015];
int a[100015];

vector<int> u[100015];
int dst[100015][15];
bool proc[100015];

void clc(int l) {
    FO(i,0,n+m) {
        dst[i][l] = 1e9;
        proc[i] = false;
    }
    deque<int> q;
    q.push_back(n+l);
    dst[n+l][l] = 0;
    while (!q.empty()) {
        int i = q.front(); q.pop_front();
        if (proc[i]) continue;
        proc[i] = true;
        for (int j : u[i]) {
            int nd = dst[i][l];
            if (i < n) {
                nd++;
            }
            if (nd < dst[j][l]) {
                dst[j][l] = nd;
                if (i < n) q.push_back(j);
                else q.push_front(j);
            }
        }
    }
}

int c[8][2<<21];

void add(vector<int> v) {
    FO(i,0,m) if (v[i] == 0) {
        int r = 0;
        int ind = 0;
        FO(j,0,m) if (j != i) {
            assert(1 <= v[j] && v[j] <= 8);
            r |= (8-v[j]) << ind;
            ind += 3;
        }
        c[i][r]++;
        return;
    }
    assert(false);
}

vector<int> mv[100005];

// num at least d apart
ll qu(int i, int d) {
    vector<int> ov(m);
    FO(j,0,m) {
        FO(k,0,m) {
            if (mv[i][j] != 8) {
                ov[k] = max(ov[k], d - (mv[i][j] + dst[j+n][k] + 1));
                ov[k] = min(ov[k],8);
            }
        }
    }
    ll res = 0;
    FO(j,0,m) if (ov[j] == 0) {
        int r = 0;
        int ind = 0;
        FO(k,0,m) if (k != j) {
            int l = ov[k];
            if (l == 0) l = 1;
            r |= (8-l) << ind;
            ind += 3;
        }
        res += c[j][r];
    }
    for (int j = i-d+1; j <= i+d-1; j++) if (0 <= j && j < n) {
        bool allgrt = true;
        FO(k,0,m) allgrt &= mv[j][k] >= ov[k];
        if (allgrt) res--;
    }
    return res;
}

ll cntg(int d) {
    ll res = 0;
    FO(i,0,n) res += qu(i, d);
    assert(res % 2 == 0);
    return res / 2;
}

int main() {
    scanf("%d %s", &n, s);
    map<char,int> seen;
    FO(i,0,n) {
        if (!seen.count(s[i])) {
            int j = sz(seen);
            seen[s[i]] = j;
        }
        a[i] = seen[s[i]];
    }
    m = sz(seen);

    FO(i,0,n) {
        if (i) u[i].push_back(i-1);
        if (i+1<n) u[i].push_back(i+1);
        u[n+a[i]].push_back(i);
        u[i].push_back(n+a[i]);
    }
    FO(i,0,m) clc(i);

    FO(i,0,n) {
        vector<int> v;
        FO(j,0,m) {
            int ldst = dst[i][j];
            if (ldst >= 8) ldst = 8;
            v.push_back(ldst);
        }
        add(v);
        mv[i] = v;
    }
    FO(i,0,m) {
        FO(j,0,m-1) {
            FO(t,0,1<<(3*(m-1))) {
                if (t & (7 << (j*3))) {
                    c[i][t] += c[i][t - (1 << (j*3))];
                }
            }
        }
    }
    ll lst = 0;
    FO(i,1,100) {
        ll nk = cntg(i);
        if (nk == 0) {
            printf("%d %lld\n", i-1, lst);
            return 0;
        }
        lst = nk;
    }
}