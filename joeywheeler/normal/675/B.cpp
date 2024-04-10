#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int a, b, c, d;
int n;

bool g(int x) {
    return 1 <= x && x <= n;
}

int main() {
    scanf("%d%d%d%d%d", &n,
            &a,&b,&c,&d);
    int res = 0;
    FO(i,1,n+1) {
        // a+b+i
        int j = b+i-c;
        int k = a+i-d;
        int l = a+b+i-c-d;
        if (g(j) && g(k) && g(l)) res++;
    }
    printf("%lld\n", res * 1ll * n);
}