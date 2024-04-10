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
#include <ctime>
#include <cassert>

using namespace std;

#define ll long long
#define double long double

const int maxn = 1 << 17;
const int inf = 1000000007;

int n, a[maxn];
vector<int> ans;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	int cur = 0, k = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cur += a[i] < 0;
		if (cur == 3) {
			ans.push_back(k);
			k = 0;
			cur = 1;
		}
		k++;
	}
	if (k)
		ans.push_back(k);

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";

	return 0;
}