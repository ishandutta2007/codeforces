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

const int MAXN = 1024;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

bool ispr(int x) {
	for (int i = 2; i * i <= x; i++) if (x % i == 0) return 0;
	return 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	vector<int> pr;
	for (int i = 2; i < MAXN; i++) {
		if (ispr(i)) {
			pr.push_back(i);
		}
	}

	int n;
	while (cin >> n) {
		vector<int> ans;
		for (int i = 0; i < (int)pr.size(); i++) {
			int cur = pr[i];
			while (cur <= n) {
				ans.push_back(cur);
				cur *= pr[i];
			}
		}
		sort(ans.begin(), ans.end());
		cout << ans.size() << endl;
		for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
	}

	return 0;
}