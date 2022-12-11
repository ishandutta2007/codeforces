#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("wa");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	cout << "YES\n";

	while (n--) {
		int xl, xr, yl, yr;
		cin >> xl >> yl >> xr >> yr;
		if (xl > xr) {
			swap(xl, xr);
		}
		if (yl > yr) {
			swap(yl, yr);
		}
		int x;
		if (xl % 2) {
			x = 1;
		} else {
			x = 0;
		}
		int y;
		if (yl % 2) {
			y = 1;
		} else {
			y = 0;
		}
		int ans = 0;
		if (x) {
			ans += 1;
		}
		if (y) {
			ans += 2;
		}
		cout << ans + 1 << "\n";
	}

}