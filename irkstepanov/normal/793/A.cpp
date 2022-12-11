#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int inf = 1e9 + 100;

int main()
{

	//ifstream cin("f.in");
	//ofstream cout("f.out");
	//freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	int minn = inf;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		minn = min(minn, a[i]);
	}
	ll ans = 0;

	for (int i = 0; i < n; ++i) {
		int x = a[i] - minn;
		if (x % k) {
			cout << "-1\n";
			return 0;
		}
		ans += x / k;
	}

	cout << ans << "\n";

}