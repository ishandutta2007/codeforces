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

const ll inf = 1e18;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	int n;
	ll d;
	cin >> n >> d;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<ll> y(n + 1);
	y[n] = 0;

	for (int i = n - 1; i >= 0; --i) {
		y[i] = max(a[i], a[i] + y[i + 1]);
	}

	int ans = 0;
	int ptr = 0;
	ll curr = 0;
	while (ptr < n) {
		if (a[ptr] > 0) {
			curr += a[ptr];
			if (curr > d) {
				cout << "-1\n";
				return 0;
			}
			++ptr;
			continue;
		}
		if (a[ptr] == 0) {
			if (curr >= 0) {
				++ptr;
				continue;
			}
			ll must = abs(curr);
			ll poss = d - y[ptr + 1] + abs(curr);
			if (must > poss) {
				cout << "-1\n";
				return 0;
			}
			curr += poss;
			if (curr > d) {
				curr = d;
			}
			++ans;
			++ptr;
			continue;
		}
		curr += a[ptr];
		++ptr;
	}

	cout << ans << "\n";

}