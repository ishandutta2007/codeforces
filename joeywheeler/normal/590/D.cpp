#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, k, s;
int f[151][151*151];
int q[155];

int main() {
    scanf("%d%d%d", &n, &k, &s);
    FO(i,0,n) scanf("%d", q+i);
    FO(i,0,k) s += i;
    int mx = 0;
    FO(i,0,n) mx += i;
    s = min(s,mx);
    FO(kk,0,k+1) FO(ss,0,s+1) {
        if (kk == 0) {
            f[kk][ss] = 0;
        } else {
            f[kk][ss] = 1e9;
        }
    }
    FO(i,0,n) {
        for (int kk = k; kk >= 1; kk--) FO(ss,i,s+1) {
            f[kk][ss] = min(f[kk][ss], f[kk-1][ss-i]+q[i]);
        }
    }
    printf("%d\n", f[k][s]);
}