#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = a; i < b; i++)

using namespace std;

int n;
int p[105];
bool s[105];

typedef long long ll;

ll gcd(ll a, ll b) {
    return a == 0 ? b : gcd(b % a, a);
}

ll lcm(ll a, ll b) {
    return a / gcd(a,b) * b;
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        scanf("%d", p+i);
        s[--p[i]] = true;
    }
    FO(i,0,n) if (!s[i]) {
        printf("-1\n");
        return 0;
    }
    memset(s,0,sizeof s);
    ll ans = 1;
    FO(i,0,n) if (!s[i]) {
        int l = 1;
        for (int j = p[i]; j != i; j = p[j]) l++;
        if (2 % l == 0) continue;
        if (l % 2 == 0) ans = lcm(ans, l/2);
        else ans = lcm(ans, l);
    }
    printf("%lld\n", ans);
}