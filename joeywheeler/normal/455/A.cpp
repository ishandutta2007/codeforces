#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

long long a[100005];

int main() {
    int n;
    scanf("%d", &n);
    FO(i,0,n) {
        int x; scanf("%d", &x);
        a[x]++;
    }
    for (int i = 100003; i >= 0; i--) a[i] = max(a[i+1], i*a[i]+a[i+2]);
    printf("%lld\n", a[0]);
}