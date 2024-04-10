#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main()
{

    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;

    vector<ll> dp;
    dp.pb(0);
    dp.pb(1);
    int s = 2;

    while (dp[s - 2] + dp[s - 1] + 1 < n) {
        dp.pb(dp[s - 2] + dp[s - 1] + 1);
        ++s;
    }

    cout << sz(dp) - 1 << "\n";

}