#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int mod = 998244353;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void sub(int& a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

int solve(vector<int>& l, vector<int>& r, int x) {
    int n = sz(l);
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        vector<int> sum(x + 1, 0);
        for (int a = 0; a <= x; ++a) {
            if (a + l[i] > x) {
                continue;
            }
            add(sum[a + l[i]], dp[a]);
            if (a + r[i] + 1 > x) {
                continue;
            }
            sub(sum[a + r[i] + 1], dp[a]);
        }
        vector<int> nx(x + 1, 0);
        nx[0] = sum[0];
        for (int a = 1; a <= x; ++a) {
            nx[a] = nx[a - 1];
            add(nx[a], sum[a]);
        }
        dp.swap(nx);
    }
    int ans = 0;
    for (int i = 0; i <= x; ++i) {
        add(ans, dp[i]);
    }
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }

    vector<int> ans(m + 1, 0);
    for (int k = 1; k <= m; ++k) {
        vector<int> a(n), b(n);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            a[i] = (l[i] + k - 1) / k;
            b[i] = r[i] / k;
            if (a[i] > b[i]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            continue;
        }
        ans[k] = solve(a, b, m / k);
    }

    vector<int> dp(m + 1, 0);
    for (int i = m; i >= 1; --i) {
        dp[i] = ans[i];
        for (int j = i * 2; j <= m; j += i) {
            sub(dp[i], dp[j]);
        }
    }

    cout << dp[1] << "\n";
    
}