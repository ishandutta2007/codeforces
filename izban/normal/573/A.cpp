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

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (scanf("%d", &n) == 1) {
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			while (a[i] % 2 == 0) a[i] /= 2;
			while (a[i] % 3 == 0) a[i] /= 3;
		}
		sort(a.begin(), a.end());
		if (a[0] == a.back()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}