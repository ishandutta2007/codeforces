#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007

using namespace std;

int n, k;
int f[105][25][25];
int nf[25][25];
vector<int> u[105];

int &g(int a[25][25], int j, int l) {
    return a[j+1][l];
}

void go(int i, int p) {
    g(f[i],-1,0) = 1;
    g(f[i],0,21) = 1;
    for (int j : u[i]) if (j != p) {
        go(j, i);

        memset(nf, 0, sizeof nf);
        FO(du,-1,22) FO(db,0,22) {
            FO(duo,-1,22) FO(dbo,0,22) {
                int ndu = du, ndb = db;
                if (duo != -1) ndu = max(ndu, duo+1);
                ndb = min(ndb, dbo+1);
                ndu = min(ndu, 21);
                g(nf, ndu, ndb) = (g(nf, ndu, ndb)+ 1ll *
                        g(f[i], du, db) * g(f[j], duo, dbo))
                    % MOD;
            }
        }
        memset(f[i], 0, sizeof f[i]);
        FO(m,-1,22) FO(l,0,22) {
            int nm = m, nl = l;
            if (m != -1 && m+l <= k) {
                nm = -1;
            }
            g(f[i], nm, nl) = (g(f[i], nm, nl) + g(nf, m, l)) % MOD;
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    FO(i,0,n-1) {
        int x, y; scanf("%d %d", &x, &y);
        u[x].push_back(y);
        u[y].push_back(x);
    }
    go(1,0);
    long long tot = 0;
    FO(i,0,22) tot += g(f[1], -1, i);
    printf("%lld\n", tot % MOD);
}