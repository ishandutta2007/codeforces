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

int n, a[maxn], ans;
vector<int> b;

/*vector<int> pr;
char p[maxn];

void getprimes(int n) {
	for (int i = 0; i <= n; i++)
		p[i] = 1;
	for (int i = 2; i <= n; i++) {
		if (p[i]) {
			if (1LL * i * i <= n) {
				for (int j = i * i; j <= n; j += i) {
					p[j] = 0;
				}
			}
		}
	}
	for (int i = 2; i <= n; i++)
		if (p[i])
			pr.push_back(i);
}

void rec(int x, int last) {

}*/

void check(int x) {
	int res = lower_bound(a, a + n + 1, x) - a;
	b.push_back(res);
}

int pow1(int x, int y) {
	if (y == 0) return 1;
	if (y == 1) return x;
	int z = pow1(x, y / 2);
	z = (1LL * z * z) % mod;
	if (y & 1)
		z = (1LL * z * x) % mod;
	return z;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a, a + n);
	int mx = a[n - 1];
	a[n] = inf;

	for (int x = 1; x <= mx; x++) {
		b.clear();
		for (int d = 1; d * d <= x; d++)
			if (x % d == 0) {
				check(d);
				if (d != x / d)
					check(x / d);
			}
		//b.push_back(-1);
		b.push_back(n);
		sort(b.begin(), b.end());
		if (b[0] == n) break;
		

		int cur = b.size();
		int cans = 1;
		bool g = 0;

		for (int i = (int)b.size() - 1; i >= 0; i--) {
			if (i < (int)b.size() - 1 && b[i] != b[i + 1]) {
				if (!g) {
					cans = (1LL * cans * pow1(i + 1, b[i + 1] - b[i])) % mod;
					if (x > 1) cans = (cans - pow1(b.size() - 2, b[i + 1] - b[i]) + mod) % mod;
					g = 1;
				} else
					cans = (1LL * cans * pow1(i + 1, b[i + 1] - b[i])) % mod;
			}
		}
		ans = (ans + cans) % mod;
	}

	cout << ans;

	return 0;
}