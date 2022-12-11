#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int tt;
	cin >> tt;

	cout << fixed;
	cout.precision(20);

	while (tt--) {
		ll d;
		cin >> d;
		ll val = d * d - 4 * d;
		if (val < 0) {
			cout << "N\n";
			continue;
		}
		vector<ld> vct = {(ld(d) + sqrt(ld(val))) / 2, (ld(d) - sqrt(ld(val))) / 2};
		bool ok = false;
		for (ld b : vct) {
			ld a = d - b;
			if (a < 0 || b < 0) {
				continue;
			}
			cout << "Y " << a << " " << b << "\n";
			ok = true;
			break;
		}
		if (!ok) {
			cout << "N\n";
		}
	}

}