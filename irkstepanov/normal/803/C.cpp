#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int inf = 1e9;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("f.out");
	//freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	ll n, k;
    cin >> n >> k;

    ll val;
    if (k >= ll(1e6)) {
        val = 1e18;
    } else {
        val = k * (k + 1) / 2;
    }

    ll bestD = -1;

    for (ll d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            if (val <= n / d) {
                bestD = max(bestD, d);
            }
            if (val <= d) {
                bestD = max(bestD, n / d);
            }
        }
    }

    if (bestD == -1) {
        cout << "-1\n";
        return 0;
    }

    ll sum = 0;
    for (int i = 1; i < k; ++i) {
        ll x = ll(i) * bestD;
        cout << x << " ";
        sum += x;
    }
    cout << n - sum << "\n";

}