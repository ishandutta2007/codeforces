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
#include <complex>
#include <cassert>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
	
	int n, k;
	map<int, set<int> > fr;
	vector<int> all;

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		fr[x].insert(y);
		fr[y].insert(x);

		all.push_back(x);
		all.push_back(y);
	}
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());

	map<int, set<int> > ans;
	for (int i = 0; i < all.size(); ++i) {
		int x = all[i];
		ans[x] = set<int>();
		for (int j = 0; j < all.size(); ++j) {
			int y = all[j];
			if (x == y || fr[x].count(y)) continue;

			int c = 0;
			for (int l = 0; l < all.size(); ++l) {
				int z = all[l];
				if (z != x && z != y && fr[x].count(z) && fr[y].count(z)) {
					++c;
				}
			}

			if (c * 100 >= k * fr[x].size()) {
				ans[x].insert(y);
			}
		}
	}

	for (auto i = ans.begin(); i != ans.end(); ++i) {
		int x = i->first;
		cout << x << ": " << i->second.size();
		for (auto j = i->second.begin(); j != i->second.end(); ++j) {
			cout << " " << *j;
		}
		cout << "\n";
	}
    
    return 0;
}