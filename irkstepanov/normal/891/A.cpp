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
typedef long double ld;
typedef pair<ll, ll> pll;

const int inf = 1e9;

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

	vector<ll> a(n);
	ll g = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		g = __gcd(g, a[i]);
	}

	if (g > 1) {
		cout << "-1\n";
		return 0;
	}

	int ones = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 1) {
			++ones;
		}
	}

	if (ones > 0) {
		cout << n - ones << "\n";
		return 0;
	}

	int ans = inf;
	for (int i = 0; i < n; ++i) {
		g = a[i];
		for (int j = i + 1; j < n; ++j) {
			g = __gcd(g, a[j]);
			if (g == 1) {
				ans = min(ans, j - i + n - 1);
				break;
			}
		}
	}

	cout << ans << "\n";

}