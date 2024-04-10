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

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;


int fct(int x) {
	return x ? fct(x - 1) * x : 1;
}

bool check(vector<int> p) {
	bool res = 1;
	for (int i = 1; i < p.size(); i++) 
		res &= p[p[i]] == (int)p.size() - 1 - i + 1;
	return res;
}

void solve(int n) {
	if (n % 4 > 1) {
		cout << "-1\n";
		return;
	}
	vector<int> p(n + 1);
	int l = 1, r = n;
	while (r - l > 1) {
		p[l + 1] = l;
		p[r - 1] = r;
		p[l] = r - 1;
		p[r] = l + 1;
		l += 2;
		r -= 2;
	}
	if (r == l) p[l] = l;
	for (int i = 1; i <= n; i++) cout << p[i] << " \n"[i == n];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/*for (int n = 1; n <= 10; n++) {
		vector<int> p(n + 1), ans;
		for (int i = 0; i <= n; i++) p[i] = i;

		for (int it = 0; it < fct(n); it++) {
			if (check(p)) {
				ans = p;
				//break;
			}
			next_permutation(p.begin(), p.end());
		}
		if (ans.size() == 0) cout << -1 << endl;
		else for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
	}*/

	int n;
	while (cin >> n)
		solve(n);	

	return 0;
}