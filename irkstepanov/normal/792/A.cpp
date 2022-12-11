#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

int main()
{

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(all(a));

	int minD = a[1] - a[0];
	int ans = 1;

	for (int i = 2; i < n; ++i) {
		int d = a[i] - a[i - 1];
		if (d < minD) {
			minD = d;
			ans = 1;
		} else if (d == minD) {
			++ans;
		}
	}

	cout << minD << " " << ans << "\n";

}