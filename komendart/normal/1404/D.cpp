//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define sz(a) ((ll)(a).size())
#define X first
#define Y second

using ll = long long;
using ull = unsigned long long;
using dbl = long double;

void solve_first(int n) {
    cout << "First" << endl;
    for (int i = 0; i < 2 * n; ++i) {
        cout << i % n + 1 << ' ';
    }
    cout << endl;
}

const int maxn = (int) 5e5 + 1000;
vector<int> pairs[maxn];
vector<int> mods[maxn];
char used[maxn];

void dfs(int mod, int pair, int id, int n) {
    if (used[pair]) {
        return;
    }
    used[pair] = true;
    if (pairs[pair][id] % n != mod) {
        reverse(pairs[pair].begin(), pairs[pair].end());
    }
    for (int i = 0; i < 2; ++i) {
        int mod = pairs[pair][i] % n;
        for (auto next: mods[mod]) {
            if (next == pair) continue;
            dfs(mod, next, i ^ 1, n);
        } 
    }
}

void solve_second(int n) {
    cout << "Second" << endl;
    for (int i = 0; i < 2 * n; ++i) {
        int x;
        cin >> x;
        pairs[x - 1].push_back(i + 1);
    }
    for (int i = 0; i < n; ++i) {
        int first = pairs[i][0] % n, second = pairs[i][1] % n;
        mods[first].push_back(i);
        mods[second].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        dfs(pairs[i][0] % n, i, 0, n);
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += pairs[i][0];
        sum %= 2 * n;
    }
    assert(sum % n == 0);
    int id = (sum % (2 * n) == 0) ? 0: 1;
    for (int i = 0; i < n; ++i) {
        cout << pairs[i][id] << ' ';
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 1) {
        solve_second(n);
    } else {
        solve_first(n);
    }
}

signed main() {
#ifdef LOCAL
    //assert(freopen("input.txt", "r", stdin));
    // assert(freopen("output.txt", "w", stdout));
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);

	solve();

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}