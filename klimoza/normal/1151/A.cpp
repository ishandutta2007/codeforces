#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")	
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;
int p = 47;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string st;
	cin >> st;
	int mini = INFi;
	for (int i = 0; i < (n - 3); i++) {
		int cnt = min(abs(st[i] - 'A'), min(st[i], 'A') - 'A' + 1 + 'Z' - max(st[i], 'A'));
		cnt += min(abs(st[i + 1] - 'C'), min(st[i + 1], 'C') - 'A' + 1 + 'Z' - max(st[i + 1], 'C'));
		//cout << cnt << endl;
		cnt += min(abs(st[i + 2] - 'T'), min(st[i + 2], 'T') - 'A' + 1 + 'Z' - max(st[i + 2], 'T'));
		cnt += min(abs(st[i + 3] - 'G'), min(st[i + 3], 'G') - 'A' + 1 + 'Z' - max(st[i + 3], 'G'));
		mini = min(mini, cnt);
	}
	cout << mini << endl;
	//system("pause");
	return 0;
}