#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const ll inf = 1e18;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> t(n + 1);
	t[0] = -inf;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
	}

	vector<ll> cost(n + 1, inf);
	cost[0] = 0;
	ll ans = 0;

	for (int i = 1; i <= n; ++i) {
		cost[i] = min(cost[i], 20 + cost[i - 1]);
		int j;
		for (j = i - 1; ; --j) {
			if (t[j] <= t[i] - 90) {
				break;
			}
		}
		++j;
		cost[i] = min(cost[i], 50 + cost[j - 1]);
		for (; ; --j) {
			if (t[j] <= t[i] - 1440) {
				break;
			}
		}
		++j;
		cost[i] = min(cost[i], 120 + cost[j - 1]);
		cout << cost[i] - ans << "\n";
		ans = cost[i];
	}

}