#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <cassert>

typedef long long ll;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

vector<int> a[111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

	int n, T;
	cin >> n >> T;
	for (int i = 0; i < n; ++i) {
		int t;
		int q;
		scanf("%d%d", &t, &q);
		a[t].push_back(q);
	}
	for (int t = 0; t < T; ++t) {
		sort(a[t].begin(), a[t].end());
		while (a[t].size() > 1) {
			int x = a[t][a[t].size() - 2];
			int y = a[t][a[t].size() - 1];
			a[t].pop_back();
			a[t].pop_back();
			a[t + 1].push_back(x + y);
		}
		if (a[t].size()) {
			a[t + 1].push_back(a[t].back());
			a[t].pop_back();
		}
	}
	sort(a[T].begin(), a[T].end());
    if (a[T].size())
    	cout << a[T].back() << endl;
    else
    	cout << 0 << endl;

    return 0;
}