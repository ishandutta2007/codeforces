#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:50000000")
typedef long long ll;

using namespace std; 

const int maxn = -1;
const int inf = 1e9;

int w, h, n;

void f(set<pair<int, int> > &sth, multiset<int> &mxh, int x) {
	set<pair<int, int> > :: iterator it = sth.lower_bound(make_pair(x, 0));
	int r = it->first;
	int xx = it->second;
	int prev = r - xx;
	multiset<int> :: iterator it2 = mxh.lower_bound(xx);
	mxh.erase(it2);
	mxh.insert(x - prev);
	mxh.insert(r - x);
	sth.erase(it);
	sth.insert(make_pair(x, x - prev));
	sth.insert(make_pair(r, r - x));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	//ios_base::sync_with_stdio(0);

	while (scanf("%d%d%d\n", &w, &h, &n) == 3) {
		set<pair<int, int> > stw, sth;
		stw.insert(make_pair(w, w));
		sth.insert(make_pair(h, h));
		stw.insert(make_pair(0, 0));
		sth.insert(make_pair(0, 0));
		multiset<int> mxw, mxh;
		mxw.insert(w);
		mxh.insert(h);

		for (int i = 0; i < n; i++) {
			char c;
			int x;
			scanf("%c%d\n", &c, &x);
			if (c == 'H') {
				f(sth, mxh, x);
			}
			if (c == 'V') {
				f(stw, mxw, x);
			}
			multiset<int> :: iterator it = mxh.end();
			it--;
			int mx1 = *it;
			it = mxw.end();
			it--;
			int mx2 = *it;
			cout << 1LL * mx1 * mx2 << "\n";
		}
	}

	return 0;
}