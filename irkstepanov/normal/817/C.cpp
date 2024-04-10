#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const ll buben = 100500;

ll f(ll val)
{
	ll ans = 0;
	while (val) {
		ans += val % 10;
		val /= 10;
	}
	return ans;
}

int main()
{

	//ifstream cin("strictly-off.in");
	//ofstream cout("strictly-off.out");
	//freopen("input.txt", "r", stdin);
	//freopen("threed.out", "w", stdout);
	//ifstream cin("input.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n, s;
	cin >> n >> s;

	ll ans = 0;
	for (ll val = s; val <= s + buben; ++val) {
		ll sum = val - f(val);
		if (sum >= s && val <= n) {
			++ans;
		}
	}

	if (s + buben + 1 <= n) {
		ans += n - (s + buben + 1) + 1;
	}

	cout << ans << "\n";
	
	//cout << "P4FN1hTc\n";

}