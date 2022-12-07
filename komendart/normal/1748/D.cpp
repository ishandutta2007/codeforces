//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define sz(a) ((ll)(a).size())
#define X first
#define Y second

using ll = long long;
using ull = unsigned long long;
using dbl = long double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll mod) {
    return (ull)rng() % mod;
}

inline int inv(int a, int b) {
	return a == 1 ? 1 : b - 1ll * inv(b % a, a) * b / a % b;
}

pair<int, int> euc(int a, int b) {
	// returns {x, y} s.t. ax + by = g
	int g = __gcd(a, b);
	a /= g, b /= g;
	int x = inv(a, b);
	int y = (1 - 1ll * a * x) / b;

	return {x, y};
}

map<int, int> bruteforce(const vector<pair<int, int>> &a, int d) {
    map<int, int> ans;
    int n = a.size();
    for (int mask = 0; mask < (1 << n); ++mask) {
        int num = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            num += a[i].first;
            sum = (sum + a[i].second) % d;
        }
        ans[sum] = num;
    }
    return ans;
}

void solve() {
    int a, b, d;
    cin >> a >> b >> d;
    int twos = 1;
    while (d % 2 == 0) {
        d /= 2;
        twos *= 2;
    }
    if (a % twos != 0 || b % twos != 0) {
        cout << -1 << '\n';
        return;
    }
    if (d == 1) {
        cout << 0 << '\n';
        return;
    }
    int diff = ((b - a) % d + d) % d;
    vector<pair<int, int>> adds;
    for (int i = 0; i < 30; ++i) {
        if (!(a & (1 << i)) && (b & (1 << i))) {
            int t = -(1 << i);
            adds.emplace_back(1 << i, (t % d + d) % d);
        } else if ((a & (1 << i)) && !(b & (1 << i))) {
            int t = 1 << i;
            adds.emplace_back(1 << i, t % d);
        }
    }
    int mid = adds.size() / 2;
    auto half = bruteforce(vector<pair<int, int>>(adds.begin(), adds.begin() + mid), d);
    adds = vector<pair<int, int>>(adds.begin() + mid, adds.end());
    int ans = -1;
    for (int mask = 0; mask < (1 << (int) adds.size()); ++mask) {
        int num = 0;
        int sum = 0;
        for (int i = 0; i < (int) adds.size(); ++i) {
            num += adds[i].first;
            sum = (sum + adds[i].second) % d;
        }
        int need = ((-diff - sum) % d + d) % d;
        if (half.count(need)) {
            //cerr << num << ' ' << sum << ' ' << need << ' ' << half[need] << ' ' << diff << endl;
            ans = num + half[need];
            break;
        }
    }
    if (ans == -1) {
        cout << -1 << '\n';
        return;
    }

    a |= ans;
    b |= ans;
    assert((b - a) % d == 0);

    int x = -a * inv((1 << 30) % d, d) % d;
    x = (x + d) % d;
    ans = ans + (x << 30);
    cout << ans << '\n';
}

signed main() {
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    // assert(freopen("output.txt", "w", stdout));
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);

    int T = 1;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}