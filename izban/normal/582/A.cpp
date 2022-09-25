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

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (scanf("%d", &n) == 1) {
		multiset<int> st;
		for (int i = 0; i < n * n; i++) {
			int x;
			scanf("%d", &x);
			st.insert(-x);
		}

		vector<int> cur;
		for (int it = 0; it < n; it++) {
			int x = -*st.begin();
			st.erase(st.begin());
			for (int i = 0; i < (int)cur.size(); i++) {
				multiset<int> ::iterator it = st.find(-gcd(cur[i], x));
				assert(it != st.end());
				st.erase(it);
				it = st.find(-gcd(cur[i], x));
				assert(it != st.end());
				st.erase(it);
			}
			cur.push_back(x);
		}

		assert(st.empty());
		for (int i = 0; i < n; i++) cout << cur[i] << " \n"[i + 1 == n];
	}

	return 0;
}