#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
//#define FILENAME "1dembedding"
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
void solve();
int main() {
#ifdef room111
    freopen("in.txt", "r", stdin);
#else
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    int t = 1;
	//cin >> t;
    while (t--)
        solve();
    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

int n;
int x[5000];

void solve() {
	cin >> n;
	int sum = 0, cel = 0;
	for (int i = 0; i < 2 * n; ++i) {
		int cur;
		scanf("%d.%d", &cur, &x[i]);
		sum += x[i];
		if (x[i] == 0)
			++cel;
	}
	int ans = 1000000000;
	for (int i = 0; i <= n; ++i) {
		if (cel >= n - i) {
			ans = min(ans, abs(sum - i * 1000));
		}
	}

	vector<int> res;
	while (ans) {
		res.push_back(ans % 10);
		ans /= 10;
	}

	while (res.size() <= 3)
		res.push_back(0);
	for (int i = res.size() - 1; i >= 3; --i)
		cout << res[i];
	cout << ".";
	for (int i = 2; i >= 0; --i)
		cout << res[i];
}