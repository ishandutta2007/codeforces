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
ll cur = 1, ans = 0;
vector<int> v;

ll gcd(ll a, ll b) {
	if (a > 0 && b > 0)
		return gcd(b, a % b);
	else
		return a + b;
}

void rec(int x) {
	if (x == 3) {
		ans = max(ans, cur);
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		ll ccur = cur;
		cur = cur * v[i] / gcd(cur, v[i]);
		rec(x+1);
		cur = ccur;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	cin >> n;
	for (int i = n; i >= max(1, n - 50); i--)
		v.push_back(i);
	rec(0);
	cout << ans;

	return 0;
}