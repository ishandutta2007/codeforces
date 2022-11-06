#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxw = 1e5 + 2;

ll cube[maxw];

ll get(ll x) {
    return (upper_bound(cube, cube + maxw, x) - cube) - 1;
}

ll ans = 0;
ll X = 0;

void rec(ll v, ll sum = 0, int depth = 0) {
    if (v == 0) {
        if (depth > ans || depth == ans && sum > X) {
            ans = depth;
            X = sum;
        }
        return;
    }
    ll a = get(v);
    rec(v - a * a * a, sum + a * a * a, depth + 1);
    if (a != 1) {
        a--;
        rec((a + 1) * (a + 1) * (a + 1) - 1 - a * a * a, sum + a * a * a, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    for (int i = 1; i < maxw; i++) {
        cube[i] = 1LL * i * i * i;
    }

    ll m;
    cin >> m;

    rec(m);

    cout << ans << ' ' << X << endl;
}