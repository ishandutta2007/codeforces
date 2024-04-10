#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD int(1e9+9)

using namespace std;

int a[300005];
int c[300005];
int f[300005];
int fc[300005];
int d[300005];
int n, m;

int ul[550], ur[550], us;

int main() {
    scanf("%d %d", &n, &m);
    FO(i,0,n) scanf("%d", &a[i]);
    FO(i,1,n+1) {
        (c[i] = c[i-1] + a[i-1]) %= MOD;
    }
    f[0] = f[1] = 1;
    FO(i,2,300005) {
        (f[i] = f[i-1] + f[i-2]) %= MOD;
    }
    FO(i,1,300005) {
        (fc[i] = fc[i-1] + f[i-1]) %= MOD;
    }
    FO(Z,0,m) {
        if (us == 550) {
            FO(i,0,us) {
                d[ul[i]] += 1;
                if (d[ul[i]] >= MOD) d[ul[i]] -= MOD;

                d[ur[i]+1] -= f[ur[i]+1-ul[i]];
                if (d[ur[i]+1] < 0) d[ur[i]+1] += MOD;

                d[ur[i]+2] -= f[ur[i]-ul[i]];
                if (d[ur[i]+2] < 0) d[ur[i]+2] += MOD;
            }
            FO(i,0,n) {
                if (i >= 1) {
                    d[i] += d[i-1];
                    if (d[i] >= MOD) d[i] -= MOD;
                }
                if (i >= 2) {
                    d[i] += d[i-2];
                    if (d[i] >= MOD) d[i] -= MOD;
                }
                a[i] += d[i];
                if (a[i] >= MOD) a[i] -= MOD;
            }
            FO(i,1,n+1) {
                c[i] = c[i-1] + a[i-1];
                if (c[i] >= MOD) c[i] -= MOD;
                d[i-1] = 0;
            }
            us = 0;
        }

        int t, l, r;
        scanf("%d %d %d", &t, &l, &r); l--; r--;
        if (t == 2) {
            int res = MOD+c[r+1]-c[l];
            res %= MOD;
            FO(i,0,us) {
                int ls = max(ul[i], l);
                int rs = min(ur[i], r);
                if (ls > rs) continue;
                ls -= ul[i]; rs -= ul[i]; // add ls to rsth fib nums
                res += fc[rs+1]-fc[ls];
                if (res < 0) res += MOD;
                else if (res >= MOD) res -= MOD;
            }
            printf("%d\n", res);
        } else {
            ul[us] = l; ur[us] = r; us++;
        }
    }
}