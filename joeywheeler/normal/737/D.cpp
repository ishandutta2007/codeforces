#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int a[4005];
int c[4005];

int f[4005][100][100];
bool sn[4005][100][100];

int dp(int l, int r, int k) {
    int &res =
        f[r][r-l][k];
    if (sn[r][r-l][k]) return res;
    sn[r][r-l][k] = true;
    res = -1e9;
    
    FO(p,0,2) {
        int nk = k+p;
        int nl = l+nk;
        if (nl+r <= n) {
            int cres = 1e9;
            FO(q,0,2) {
                int nnk = nk+q;
                int nr = r+nnk;
                if (nl+nr <= n) {
                    cres = min(cres, dp(nl, nr, nnk));
                } else if (q == 0) {
                    cres = c[nl]-(c[n]-c[n-r]);
                }
            }
            res = max(res, cres);
        } else if (p == 0) {
            res = c[l]-(c[n]-c[n-r]);
        }
    }

    return res;
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        scanf("%d", a+i);
        c[i+1] = c[i] + a[i];
    }

    printf("%d\n", dp(0,0,1));
}