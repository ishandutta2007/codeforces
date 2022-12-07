#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
int n;
ll m;

int ans[55], vis[55];
int an = 0;

ll pow_mod(ll x, int k) {
    ll ans = 1;
    while (k) {
        if (k&1) ans *= x;
        x *= x;
        k >>= 1;
    }
    return ans;
}

int main() {
    scanf("%d%lld", &n, &m);
    int pre = 1;
    for (int i = 1; i < n; i++) {
        for (; pre < n; pre++) {
            if (m > pow_mod(2LL, n - pre - 1)) {
                m -= (pow_mod(2LL, n - pre - 1));
            } else {
                vis[pre] = 1;
                ans[an++] = pre++;
                break;
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        if (vis[i]) continue;
        ans[an++] = i;
    }
    for (int i = 0; i < n; i++)
        printf("%d%c", ans[i], i == n ? '\n' : ' ');
    return 0;
}