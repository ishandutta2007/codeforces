#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef unsigned int uuint;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //ifstream cin("input.txt");

    int n;
    cin >> n;

    vector<pii> v(n);
    forn(i, n) {
        cin >> v[i].first >> v[i].second;
    }

    sort(all(v));

    vector<int> dp(n);///rests
    dp[0] = 1;

    forn(i, n) {
        int l = 0, r = i - 1;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (v[m].first < v[i].first - v[i].second) {
                l = m;
            } else {
                r = m;
            }
        }
        if (v[r].first < v[i].first - v[i].second) {
            dp[i] = 1 + dp[r];
        } else if (v[l].first < v[i].first - v[i].second) {
            dp[i] = 1 + dp[l];
        } else {
            dp[i] = 1;
        }
    }

    int ans = -1;
    forn(i, n) {
        ans = max(ans, dp[i]);
    }

    cout << n - ans << "\n";

}