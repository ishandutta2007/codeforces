#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
ll alarm[303030];
ll dist[303030];
ll p[303030];
int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        scanf("%lld", &alarm[i]);
    }

    for (int i=0; i<m; i++) {
        scanf("%lld", &p[i]);
    }


    for (int i=0; i<n-1; i++) {
        dist[i] = alarm[i+1]-alarm[i];
    }

    ll gcd = 0;

    for (int i=0; i<n-1; i++) {
        gcd = __gcd(gcd, dist[i]);
    }

    for (int i=0; i<m; i++) {
        if (gcd%p[i] == 0) {
            printf("YES\n");
            printf("%lld %d", alarm[0], i+1);
            return 0;
        }
    }

    printf("NO");
}