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

const int maxn = 1 << 20;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m;
int a[maxn], b[maxn];

int f() {
	int cur = 0;
	for (int i = 0; i < n; i++) {
		int x = a[i];
		while (cur < m && x >= (1 << b[cur])) x -= 1 << b[cur++];
	}
	return cur;
}

int fastsolve() {
	sort(a, a + n);
	sort(b, b + m);
	//reverse(a, a + n);
	//reverse(b, b + m);
	return f();
}

int k[32];
ll k2[32];
bool F(int x) {
	for (int i = 0; i < 32; i++) k2[i] = k[i];
	bool res = 1;
	int cur = 30;
	for (int i = x - 1; i >= 0; i--) {
		while (cur > b[i]) {
			k2[cur - 1] += 2 * k2[cur];
			cur--;
		}
		if (k2[cur] == 0) res = 0;
		k2[cur]--;
	}
	return res;
}

int fastsolve2() {
	sort(b, b + m);
	memset(k, 0, sizeof(k));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 30; j++)
			k[j] += (a[i] & (1 << j)) > 0;

	int l = 0, r = m;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		if (F(m)) l = m;
		else r = m;
	}
	if (F(r)) return r;
	else return l;
}

void reading() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);
}

int fct(int x) {
	return x ? x * fct(x - 1) : 1;
}

int slowsolve() {
	int ans = 0;
	for (int it = 0; it < fct(m); it++) {
		ans = max(ans, f());
		next_permutation(b, b + m);
	}
	return ans;
}

void gen() {
	n = rand() % 100 + 1;
	m = rand() % 9 + 1;
	for (int i = 0; i < n; i++) a[i] = rand() % 1000000000 + 1;
	for (int i = 0; i < m; i++) b[i] = rand() % 30;
}

void stress() {
	for (int it = 0; it < 10000; it++) {
		gen();
		if (fastsolve2() != slowsolve()) {
			cout << n << " " << m << endl;
			for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
			for (int i = 0; i < m; i++) cout << b[i] << " \n"[i == m - 1];
			cout << fastsolve2() << " " << slowsolve() << endl;
			break;
		}
		cerr << it << endl;
	}
	exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	if (0) stress();

	reading();
	cout << fastsolve2() << endl;

	return 0;
}