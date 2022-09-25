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

using namespace std;

#define ll long long


const int maxn = 1 << 17;

int n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	cin >> n;
	vector<int> a(n), b;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	b = a;
	sort(b.begin(), b.end());
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += b[i] != a[i];
	if (ans > 2) cout << "NO";
	else 
		cout << "YES";

	return 0;
}