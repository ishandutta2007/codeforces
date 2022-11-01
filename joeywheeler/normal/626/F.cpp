#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, k;
int a[205];
int b[205];
int c[205][205][1005];

long long f(int i, int o, int s) {
    if (o < 0) return 0;
    s += b[i]*o;
    if (s > k) return 0;
    if (i == n) {
        return o==0;
    }
    if (c[i][o][s] != -1) return c[i][o][s];
    long long res = 0;
    // assign to old
    res += f(i+1,o,s) * o;
    // make open
    res += f(i+1,o+1,s);
    // make close
    res += f(i+1,o-1,s) * o;
    // assign to self
    res += f(i+1,o,s);

    res %= 1000000007;
    c[i][o][s] = res;

    return res;
}

int main() {
    memset(c,-1,sizeof c);
    scanf("%d%d", &n, &k);
    FO(i,0,n) scanf("%d", a+i);
    sort(a,a+n);
    FO(i,1,n) b[i] = a[i]-a[i-1];
    printf("%lld\n", f(0,0,0));
}