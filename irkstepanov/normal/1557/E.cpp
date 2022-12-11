#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

void solve() {
	cout << "1 1" << endl;
	string s;
	cin >> s;
	if (s == "Done") {
		return;
	}
	for (int x = 1; x <= 8; ++x) {
		// start at (x, 1)
		int type = 0;
		int yf = 8;
		for (int y = 2; y <= 8; ++y) {
			cout << x << " " << y << endl;
			cin >> s;
			if (s == "Done") {
				return;
			}
			if (s == "Left" || s == "Right") {
				continue;
			}
			if (s == "Down" || s == "Down-Right" || s == "Down-Left") {
				type = 1;
				yf = y;
				break;
			} else {
				type = -1;
				yf = y;
				break;
			}
		}
		if (type == 0 || type == 1) {
			cout << x + 1 << " " << yf << endl;
			cin >> s;
			if (s == "Done") {
				return;
			}
			cout << x + 1 << " " << 1 << endl;
			cin >> s;
			if (s == "Done") {
				return;
			}
		} else {
			cout << x << " " << 1 << endl;
			cin >> s;
			if (s == "Done") {
				return;
			}
			if (s == "Down" || s == "Down-Right" || s == "Down-Left") {
				cout << x + 1 << " " << 1 << endl;
				cin >> s;
				if (s == "Done") {
					return;
				}
			} else {
				--x;
			}
		}
	}
	assert(false);
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int tt;
    cin >> tt;

    while (tt--) {
    	solve();
    }

}