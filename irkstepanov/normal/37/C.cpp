#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int nmax = 1050;

vector<int> v[nmax];

bool add(string& s) {
	for (int j = sz(s) - 1; j >= 0; --j) {
		if (s[j] == '0') {
			s[j] = '1';
			return true;
		}
		s[j] = '0';
	}
	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		v[x].pb(i);
	}

	for (int i = 1; i < 20; ++i) {
		if (sz(v[i]) > (1 << i)) {
			cout << "NO\n";
			return 0;
		}
	}

	vector<string> ans(n);

	string pr = "";

	for (int len = 1; len < nmax; ++len) {
		while (!v[len].empty()) {
			int id = v[len].back();
			v[len].pop_back();
			if (pr == "") {
				for (int i = 0; i < len; ++i) {
					pr += "0";
				}
				ans[id] = pr;
				continue;
			}
			if (!add(pr)) {
				cout << "NO\n";
				return 0;
			}
			while (sz(pr) < len) {
				pr += "0";
			}
			ans[id] = pr;
		}
	}

	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << "\n";
	}

}