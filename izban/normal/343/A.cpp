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


ll gcd(ll a, ll b) {
	while (b) b ^= a ^= b ^= a %= b;
	return a;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll a, b;
	while (cin >> a >> b) {
		ll ans = 0;
		if (a > b) swap(a, b);
		while (a && b) {
			ans += a / b;
			b ^= a ^= b ^= a %= b;
		}
		cout << ans << endl;
	}

	return 0;
}