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
const string ans[2] = {"NO\n", "YES\n"};

ll p, q;
int n;
vector<ll> a;

bool f(ll p, ll q, vector<ll> a) {
	if (q == 0) return 0;
	if (a.size() == 1) return p / q == a[0] && p % q == 0;
	if (p / q < a[0]) return 0;
	p -= q * a[0];
	for (int i = 0; i < a.size() - 1; i++) a[i] = a[i + 1];
	a.resize(a.size() - 1);
	swap(p, q);
	return f(p, q, a);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> p >> q >> n) {
		a.resize(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		cout << ans[f(p, q, a)];
	}

	return 0;
}