#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pll;

int main()
{

    //ifstream cin("input.txt");

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> sorted = a;
    sort(all(sorted));
    sorted.resize(unique(all(sorted)) - sorted.begin());

    int k = sz(sorted);

    vector<ll> dp(k);
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(all(sorted), a[i]) - sorted.begin();
    }
    for (int i = 0; i < k; ++i) {
        int x = sorted[a[0]];
        int y = sorted[i];
        dp[i] = (ll)abs(x - y);
    }

    for (int i = 1; i < n; ++i) {
        vector<ll> dp_new(k);
        ll minn = dp[0];
        for (int j = 0; j < k; ++j) {
            minn = min(minn, dp[j]);
            int x = sorted[a[i]];
            int y = sorted[j];
            dp_new[j] = minn + (ll)abs(x - y);
        }
        dp.swap(dp_new);
    }

    ll ans = dp[0];
    for (int i = 1; i < k; ++i) {
        ans = min(ans, dp[i]);
    }

    cout << ans << "\n";

}