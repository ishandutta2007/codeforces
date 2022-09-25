#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 7;
const int inf = 1000000007;
const int mod = 1000000007;


int n, a[maxn];
int b[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		memset(b, 0, sizeof(b));
		for (int i = 0; i < n; i++) cin >> a[i], b[a[i]] = 1;
		vector<int> ans;
		if (b[100]) ans.push_back(100);
		if (b[0]) ans.push_back(0);
		for (int i = 1; i <= 9; i++) if (b[i]) { ans.push_back(i); break;}
		for (int i = 10; i <= 90; i += 10) if (b[i]) {ans.push_back(i); break;}
		sort(ans.begin(), ans.end());
		if (ans.size() == (int)binary_search(ans.begin(), ans.end(), 0) + (int)binary_search(ans.begin(), ans.end(), 100)) {
			for (int i = 0; i < n; i++) if (a[i] != 0 && a[i] != 100) {
				ans.push_back(a[i]);
				break;
			}
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) cout << ans[i] << " \n"[i + 1 == ans.size()];
	}

	return 0;
}