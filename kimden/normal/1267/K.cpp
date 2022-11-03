#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

ull C[55][55];

inline ll get_c(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    return C[n][k];
}

ll solve(const vector<int>& v) {
    ll ans = 1;
    int ptr = 0;
    while (ptr < (int)v.size()) {
        int nxt = ptr;
        while (nxt < (int)v.size() && v[ptr] == v[nxt])
            ++nxt;
        if (v[ptr] > ptr + 1)
            return 0;
        int borders = ptr + 1 - max(1, v[ptr]);
        ans *= get_c(nxt - ptr + borders, borders);
        ptr = nxt;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 55; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }

    int ttt;
    cin >> ttt;
    for (int tst = 1; tst <= ttt; ++tst) {
        ll x;
        cin >> x;
        vector<int> v;
        for (int i = 2; x > 0; ++i) {
            v.push_back(x % i);
            x /= i;
        }
        sort(all(v));

        ll ans = solve(v);
        if (v[0] == 0) {
            v.erase(v.begin());
            ll ans_0 = solve(v);
            //cerr << ans << " " << ans_0 << endl;
            ans -= ans_0;
        }
        --ans;
        cout << ans << '\n';
    }
}