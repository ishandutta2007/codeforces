#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

bool bit(ll mask, int pos)
{
    return mask & (1LL << pos);
}

int main()
{

    ios::sync_with_stdio(false);

    ll s, x;
    cin >> s >> x;
    ll dp[2];
    dp[0] = 1;
    dp[1] = 0;

    for (int i = 0; i < 60; ++i) {
        ll dpNew[2] = {0, 0};
        if (bit(x, i)) {
            if (bit(s, i)) {
                dpNew[0] = dp[0] * 2;
            } else {
                dpNew[1] = dp[1] * 2;
            }
        } else {
            if (bit(s, i)) {
                dpNew[0] = dp[1];
                dpNew[1] = dp[1];
            } else {
                dpNew[0] = dp[0];
                dpNew[1] = dp[0];
            }
        }
        dp[0] = dpNew[0];
        dp[1] = dpNew[1];
    }

    if (s == x) {
        dp[0] -= 2;
    }

    cout << dp[0] << "\n";

}