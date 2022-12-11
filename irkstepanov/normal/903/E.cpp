#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

bool correct(const string& a, const string& b) {
	vector<int> vct;
	for (int i = 0; i < sz(a); ++i) {
		if (a[i] != b[i]) {
			vct.pb(i);
		}
	}
	if (sz(vct) == 0) {
		assert(a == b);
		set<char> setik;
		for (int i = 0; i < sz(a); ++i) {
			if (setik.count(a[i])) {
				return true;
			}
			setik.insert(a[i]);
		}
		return false;
	}
	if (sz(vct) != 2) {
		return false;
	}
	string t = a;
	swap(t[vct[0]], t[vct[1]]);
	return t == b;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	int k, n;
	cin >> k >> n;

	vector<string> s(k);
	for (int i = 0; i < k; ++i) {
		cin >> s[i];
	}

	int j0 = -1;
	for (int j = 0; j < n; ++j) {
		set<char> setik;
		for (int i = 0; i < k; ++i) {
			setik.insert(s[i][j]);
		}
		if (sz(setik) > 1) {
			j0 = j;
		}
	}

	if (j0 == -1) {
		swap(s[0][0], s[0][1]);
		cout << s[0] << "\n";
		return 0;
	}

	vector<int> check;
	for (int i = 0; i < k; ++i) {
		for (int j = i + 1; j < k; ++j) {
			if (s[i][j0] != s[j][j0]) {
				check = {i, j};
				break;
			}
		}
		if (!check.empty()) {
			break;
		}
	}

	//cout << j0 << endl;

	for (int i0 : check) {
		for (int j = 0; j < n; ++j) {
		    if (j == j0) {
		        continue;
		    }
			swap(s[i0][j0], s[i0][j]);

			bool ok = true;
			for (int i = 0; i < k; ++i) {
				if (i == i0) {
					continue;
				}
				ok &= correct(s[i], s[i0]);
				if (!ok) {
					break;
				}
			}

			if (ok) {
				cout << s[i0] << "\n";
				return 0;
			}

			swap(s[i0][j0], s[i0][j]);
		}
	}

	cout << "-1\n";

}