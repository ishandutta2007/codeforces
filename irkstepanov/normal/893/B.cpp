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

bool good(int x) {
	int a = 0, b = 0;
	int state = 0;
	while (x) {
		if (x & 1) {
			if (state == 0) {
				state = 1;
			}
			++a;
		} else {
			if (state == 1) {
				return false;
			}
			++b;
		}
		x >>= 1;
	}
	return a - 1 == b;
}

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

	int ans = 1;
	for (int d = 2; d <= n; ++d) {
		if (n % d == 0 && good(d)) {
			ans = d;
		}
	}

	cout << ans << "\n";

}