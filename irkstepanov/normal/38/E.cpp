#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const ll inf = 1e18;

struct ball
{
    ll x, c;
    bool operator<(const ball& other) const
    {
        return x < other.x;
    }
};

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    cin >> n;

    vector<ball> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i].x >> b[i].c;
    }
    sort(all(b));

    vector<ll> dp(n, inf);
    dp[0] = b[0].c;

    for (int i = 1; i < n; ++i) {
        ll sum = 0;
        for (int j = i - 1; j >= 0; --j) {
            dp[i] = min(dp[i], dp[j] + sum - (ll)(i - j - 1) * b[j].x + b[i].c);
            sum += b[j].x;
        }
    }

    ll ans = inf;
    ll sum = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans = min(ans, dp[i] + sum - (ll)(n - i - 1) * b[i].x);
        sum += b[i].x;
    }
    cout << ans << "\n";

}