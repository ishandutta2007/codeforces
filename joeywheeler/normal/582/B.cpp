#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

#define K 90

int a[K*105];
int f[K*105];
int n, t;

int main() {
    scanf("%d %d", &n, &t);
    FO(i,0,n) scanf("%d", &a[i]);
    FO(i,n,K*n) a[i] = a[i-n];
    FO(i,0,K*n) {
        f[i] = 1;
        FO(j,0,i) if (a[j] <= a[i]) f[i] = max(f[i],f[j]+1);
    }
    int res = 0;
    if (t <= K) {
        FO(i,0,t*n) res = max(res, f[i]); printf("%d\n", res);
        return 0;
    }
    //FO(i,(K-1)*n,K*n) {
        //assert(f[i]-f[i-n] == f[i-n]-f[i-2*n]);
    //}
    FO(i,(K-1)*n,K*n) {
        int d = f[i]-f[i-n];
        //f[i+r*n] = f[i] + r*d;
        int r = t-K;
        res = max(res, f[i] + r*d);
    }
    printf("%d\n", res);
    return 0;
}