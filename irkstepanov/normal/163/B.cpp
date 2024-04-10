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

struct data {
	ll first;
	ll second;
	int id;
	bool operator<(const data& other) const {
		if (first != other.first) {
			return first < other.first;
		}
		return second < other.second;
	}
};

const ld eps = 1e-9;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	int n, k;
	ll h;
	cin >> n >> k >> h;
    h = 1;

	vector<data> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i].second;
		a[i].id = i + 1;
	}
	sort(all(a));

	ld lf = 0, rg = 1e5 + 100;

	for (int op = 0; op < 100; ++op) {
		ll ptr = 1;
		ld t = (lf + rg) / 2;
		for (int i = 0; i < n; ++i) {
			if (ptr * h <= t * a[i].second) {
				++ptr;
			}
			if (ptr == k + 1) {
				break;
			}
		}
		if (ptr == k + 1) {
			rg = t;
		} else {
			lf = t;
		}
	}

	for (ld t = rg - 500 * eps; ; t += eps) {
		vector<int> ans;
		ll ptr = 1;
		for (int i = 0; i < n; ++i) {
			if (ptr * h <= t * a[i].second) {
				ans.pb(a[i].id);
				++ptr;
			}
			if (ptr == k + 1) {
				break;
			}
		}
		if (sz(ans) == k) {
			for (int x : ans) {
				cout << x << " ";
			}
			cout << "\n";
			return 0;
		}
	}

}