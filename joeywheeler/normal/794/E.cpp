#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int a[300005];
int res[300005];

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        scanf("%d", a+i);
    }
    FO(i,0,n-1) {
        // want i,i+1 to be mid
        // need even num things
        int vl = max(a[i],a[i+1]);
        int ln = 2;
        ln += 2*min(i, n-i-2);
        res[n-ln] = max(res[n-ln], vl);
    }
    FO(i,0,n-2) {
        // want i,i+1,i+2 to be mid
        int vl = min(a[i+1],max(a[i], a[i+2]));
        int ln = 3;
        ln += 2*min(i, n-i-3);
        res[n-ln] = max(res[n-ln], vl);
    }
    FO(i,2,n) {
        res[i] = max(res[i], res[i-2]);
    }
    res[n-1] = 0;
    FO(i,0,n) res[n-1] = max(res[n-1], a[i]);
    FO(i,0,n) printf("%d%c", res[i], " \n"[i+1==n]);
}