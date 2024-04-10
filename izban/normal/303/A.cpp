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

int fct(int x) {
	return x ? x * fct(x - 1) : 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n) {
		if (n & 1) {
			for (int i = 0; i < n; i++) cout << i << " \n"[i == n - 1];
			for (int i = 0; i < n; i++) cout << i << " \n"[i == n - 1];
			for (int i = 0; i < n; i++) cout << (i + i) % n << " \n"[i == n - 1];
		} else cout << -1 << endl;
	}
	return 0;

	for (n = 1; n <= 10; n++) {
		vector<int> a(n), b(n), c(n);
		for (int i = 0; i < n; i++) a[i] = b[i] = i;
		bool ans = 0;
		for (int it = 0; it < fct(n); it++) {
			vector<int> f(n, 0);
			ans = 1;
			for (int i = 0; i < n; i++) {
				c[i] = (a[i] + b[i]) % n;
				f[c[i]]++;
				ans &= f[c[i]] == 1;
			}
			if (ans) {
				for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
				for (int i = 0; i < n; i++) cout << b[i] << " \n"[i == n - 1];
				for (int i = 0; i < n; i++) cout << c[i] << " \n"[i == n - 1];
				break;
			}
			next_permutation(b.begin(), b.end());
		}
		if (!ans) {
			cout << -1 << endl;
		}
	}

	return 0;
}