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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	vector<pll> v;
	for (int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		ll b = sqrt(a);
		pll p = {0, 0};
		p.first = min(a - b * b, (b + 1) * (b + 1) - a);
		if (b * b == a) {
			if (a == 0) {
				p.second = 2;
			} else {
				p.second = 1;
			}
		}
		v.pb(p);
	}

	sort(all(v), [&] (pll x, pll y) {
		return x.second - x.first < y.second - y.first;
	});

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += v[i].first;
	}
	for (int i = 0; i < n / 2; ++i) {
		ans += v[i].second - v[i].first;
	}

	cout << ans << "\n";

}