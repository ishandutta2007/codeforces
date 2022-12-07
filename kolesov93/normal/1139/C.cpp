#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);
const ll MOD = 1000000007;

ll mypow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res = (res * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return res;
}

const int N = 100111;
vector<int> g[N];
bool used[N];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (c == 0) {
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }

    ll ans = mypow(n, k);
    for (int i = 1; i <= n; ++i) {
        if (used[i]) {
            continue;
        }

        int cnt = 0;
        queue<int> q; q.push(i);
        used[i] = true;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            ++cnt;
            for (int y : g[x]) {
                if (!used[y]) {
                    used[y] = true;
                    q.push(y);
                }
            }
        }
        ans = (ans + MOD - mypow(cnt, k)) % MOD;
    }
    cout << ans << endl;

    return 0;
}