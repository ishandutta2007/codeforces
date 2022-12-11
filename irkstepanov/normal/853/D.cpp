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

const int kmax = 100;
const ll inf = 1e18;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    vector<ll> dp(kmax, inf);
    dp[0] = 0;

    int n;
    //n = 300500;
    cin >> n;

    while (n--) {
        int a;
        //a = (rr() % 2 + 1) * 1000;
        cin >> a;
        a /= 100;
        vector<ll> nx(kmax, inf);
        for (int i = 0; i < kmax; ++i) {
            if (dp[i] == inf) {
                continue;
            }
            if (i + a / 10 < kmax) {
                nx[i + a / 10] = min(nx[i + a / 10], dp[i] + a);
            }
            if (i > 0) {
                int spend = min(a, i);
                nx[i - spend] = min(nx[i - spend], dp[i] + ll(a - spend));
            }
        }
        dp.swap(nx);
    }

    ll ans = inf;
    for (int i = 0; i < kmax; ++i) {
        ans = min(ans, dp[i]);
    }
    cout << ans << "00\n";

}