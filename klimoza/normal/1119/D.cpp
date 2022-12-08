#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>

using namespace std;

typedef long long ll;

ll INF = 4e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	ll n;
	cin >> n;
	vector<ll> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s.begin(), s.end());
	vector<ll> f(n - 1);
	for (int i = 0; i < n - 1; i++) {
		f[i] = s[i + 1] - s[i];
	}
	sort(f.begin(), f.end());
	vector<ll> pref(n);
	pref[0] = 0;
	for (int i = 0; i < n - 1; i++) {
		pref[i + 1] = pref[i] + f[i];
	}
	int q;
	cin >> q;
	ll l, r;
	while (q--) {
		cin >> l >> r;
		if (n == 1) {
			cout << r - l + 1 << endl;
		}
		else {
			ll le = 0;
			ll re = n - 1;
			while (re - le > 1) {
				ll mid = (re + le) / 2;
				if (f[mid] <= (r - l + 1)) le = mid;
				else re = mid;
			}
			//cout << le << endl;
			if (f[le] > (r - l + 1)) le = -1;
			cout << (r - l + 1) * (n - le - 1) + pref[le + 1] << " ";
		}
	}
	//system("pause");
	return 0;
}