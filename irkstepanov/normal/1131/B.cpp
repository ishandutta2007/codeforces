#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	int n;
	cin >> n;

	int a = 0, b = 0;
	int ans = 1;

	while (n--) {
		int c, d;
		cin >> c >> d;
		int minn = max(a, b);
		int maxx = min(c, d);
		if (minn <= maxx) {
			if (a == minn && b == minn) {
				ans += maxx - minn;
			} else {
				ans += maxx - minn + 1;
			}
		}
		a = c, b = d;
	}
	cout << ans << "\n";
	

}