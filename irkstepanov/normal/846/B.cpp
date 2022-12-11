#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const ll inf = 1e18;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

	int n, k;
    ll total;
    cin >> n >> k >> total;

    vector<ll> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    int maxScore = (k + 1) * n;

    vector<ll> dp(maxScore + 1, inf);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        vector<ll> nx = dp;
        for (int curr = 0; curr <= maxScore; ++curr) {
            if (dp[curr] < inf) {
                ll sum = 0;
                for (int j = 0; j < k; ++j) {
                    sum += a[j];
                    if (dp[curr] + sum <= total) {
                        nx[curr + j + 1 + (j == k - 1)] = min(nx[curr + j + 1 + (j == k - 1)], dp[curr] + sum);
                    }
                }
            }
        }
        dp.swap(nx);
    }

    int ans = 0;
    for (int i = 0; i <= maxScore; ++i) {
        if (dp[i] <= total) {
            ans = i;
        }
    }
    cout << ans << "\n";

}