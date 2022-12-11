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

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(all(a));

	if (k == 1) {
		cout << n << "\n";
		return 0;
	}

	int ans = 0;
	int lf = 0;
	int cnt = 1;
	vector<int> alive(n, 1);
	for (int i = 1; i < n; ++i) {
		++cnt;
		while (a[i] - a[lf] + 1 > m) {
			cnt -= alive[lf];
			++lf;
		}
		if (cnt >= k) {
			alive[i] = 0;
			--cnt;
			++ans;
		}
	}

	cout << ans << "\n";

}