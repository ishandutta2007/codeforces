#include <unordered_map>
#include <unordered_set>
#include <functional>
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


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n; i++) ans = (ans + 1LL * a[i] * a[n - 1 - i]) % 10007;
	cout << ans << endl;

	return 0;
}