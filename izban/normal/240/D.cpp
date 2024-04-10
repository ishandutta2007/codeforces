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
#pragma comment(linker, "/STACK:64000000")


const int maxn = 1 << 17;

int n, m;
vector<int> a, b, c, Ans, Ansa;

bool check() {
	int i = 0;
	while (i < c.size() && c[i] == 1)
		i++;
	while (i < c.size() && c[i] == 0)
		i++;
	return i == c.size();
}

void solve(int x) {
	vector<int> c, ans, ansa;
	int cur = x;
	int l = 0, r = 0;
	while (l < n || r < m) {
		while (l < n && a[l] == cur) {
			ans.push_back(l + 1);
			c.push_back(cur);
			l++;
		}
		while (r < m && b[r] == cur) {
			ans.push_back(n + r + 1);
			c.push_back(cur);
			r++;
		}
		cur ^= 1;
	}
	
	bool flag = check() && 0;
	for (int i = 0; i < n+m; i++) {
		if ((i == n+m-1 && c[i] == 1 && !flag) || (i < n+m-1 && c[i + 1] != c[i]))
			ansa.push_back(i+1);
	}

	if (x == 0) {
		Ans = ans;
		Ansa = ansa;
	}
	if (x == 1 && ansa.size() < Ansa.size()) {
		Ans = ans;
		Ansa = ansa;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}

	solve(0);
	solve(1);


	for (int i = 0; i < Ans.size(); i++)
		printf("%d ", Ans[i]);
	printf("\n");
	printf("%d\n", Ansa.size());
	for (int i = 0; i < Ansa.size(); i++)
		printf("%d ", Ansa[i]);
	printf("\n");

	return 0;
}