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


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
ll ans;
vector<int> p, pans;

int fct(int n) {
	return n ? n * fct(n - 1) : 1;
}

void solve(int n) {
	p.assign(n + 1, 0);
	p[0] = n;
	int c = 0, cp = 2, k = 0;
	for (int i = 1; i <= n; i++) {
		p[i] = c + (n - i) / cp * cp;
		c--;
		if (c < 0) {
			cp *= 2;
			k = 2 * k + 1;
			c = k;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	cin >> n;
	//for (n = 1; n <= 11; n++) {
	solve(n);
	for (int i = 0; i <= n; i++)
		ans += i ^ p[i];
	cout << ans << endl;
	for (int i = 0; i <= n; i++)
		printf("%d ", p[i]);
		//cout << p[i] << " \n"[i == n];
	//}
	return 0; 

	for (n = 1; n <= 11; n++) {
		p.clear(); ans = -1;
		for (int i = 0; i <= n; i++)
			p.push_back(i);

		int o = fct(n + 1);
		for (int it = 0; it < o; it++) {
			int cans = 0;
			for (int i = 0; i <= n; i++)
				cans += i ^ p[i];
			if (cans >= ans) {
				ans = cans;
				pans = p;
			}
			next_permutation(p.begin(), p.end());
		}
		for (int i = 0; i <= n; i++)
			cout << pans[i] << " \n"[i == n];
	}

	return 0;
}