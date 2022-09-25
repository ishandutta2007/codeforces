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

int n;
int a[maxn];

ll gcd(ll a, ll b) {
	while (b) b ^= a ^= b ^= a %= b;
	return a;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);

	ll ansa = 0, ansb = n, sum = 0;
	for (int i = 0; i < n; i++) {
		ansa += 2 * (1LL * i * a[i] - sum);
		sum += a[i];
	}
	for (int i = 0; i < n; i++) ansa += a[i];
	ll g = gcd(ansa, ansb);
	ansa /= g;
	ansb /= g;
	cout << ansa << " " << ansb << endl;

	return 0;
}