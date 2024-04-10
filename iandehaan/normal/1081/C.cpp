#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

ll mod = 998244353;

ll n, m, k;
ll memo[3000][3000];

ll dp(ll place, ll nums) {
    if (nums < 0) return 0;
    if (place == 0) {
        if (nums == 0) return m;
        else return 0;
    }

    if (memo[place][nums] != -1) return memo[place][nums];

    ll out = dp(place-1, nums-1)*(m-1);
    out += dp(place-1, nums)*(1);
    out %= mod;
    //cout << "place=" << place << " nums=" << nums << " out=" << out << endl;
    return memo[place][nums] = out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    memset(memo, -1, sizeof memo);
    cout << dp(n-1, k)%mod << endl;
}