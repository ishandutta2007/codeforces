#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

const int nmax = 100500;

ll dp[2][5];

const ll inf = 1e18;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    string hard = "hard";
    int ptr = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            dp[ptr ^ 1][j] = inf;
        }
        for (int j = 0; j < 4; ++j) {
            if (s[i] == hard[j]) {
                dp[ptr ^ 1][j] = min(dp[ptr ^ 1][j], dp[ptr][j] + a[i]);
                dp[ptr ^ 1][j + 1] = min(dp[ptr ^ 1][j + 1], dp[ptr][j]);
            } else {
                dp[ptr ^ 1][j] = min(dp[ptr ^ 1][j], dp[ptr][j]);
            }
        }
        ptr ^= 1;
    }

    ll ans = 1e18;
    for (int j = 0; j < 4; ++j) {
        ans = min(ans, dp[ptr][j]);
    }
    cout << ans << "\n";

}