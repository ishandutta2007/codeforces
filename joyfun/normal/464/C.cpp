#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const int N = 100005;

char str[N], sss[N];
int n;

ll pow_mod(ll x, ll k) {
    ll ans = 1;
    while (k) {
        if (k&1) ans = (ans * x) % MOD;
        x = x * x % MOD;
        k >>= 1;
    }
    return ans;
}

ll v[15], l[15];

ll idx(char c) {
    return c - '0';
}

struct State {
    ll u;
    vector<ll> v;
    void init(char *str) {
        int len = strlen(str);
        u = idx(str[0]);
        v.clear();
        for (int i = 3; i < len; i++)
            v.push_back(idx(str[i]));
    }
} s[N];

int main() {
    scanf("%s", str);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", sss);
        s[i].init(sss);
    }
    for (int i = 0; i < 10; i++) {
        v[i] = i;
        l[i] = 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        ll lt = 0, vt = 0;
        for (int j = 0; j < s[i].v.size(); j++) {
            ll nu = s[i].v[j];
            vt = (vt * pow_mod(10, l[nu]) % MOD + v[nu]) % MOD;
            lt = (lt + l[nu]) % (MOD - 1);
        }
        v[s[i].u] = vt;
        l[s[i].u] = lt;
    }
    ll ans = 0;
    for (int i = 0; i < strlen(str); i++) {
        ll nu = idx(str[i]);
        ans = (ans * pow_mod(10, l[nu]) % MOD + v[nu]) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}