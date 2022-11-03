#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>

using namespace std;
//#define LOCAL
const int mod = 1e9 + 7;

long long back(long long t) {
	int up = mod - 2;
	long long now = t;
	t = 1;
	while (up) {
		if (up & 1)
			t = (t * now) % mod;
		up >>= 1;
		now = (now * now) % mod;
	}
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n == 1) {
		cout << a[0];
		return 0;
	}
	if (n % 2 == 1) {
		for (int i = 0; i < n - 1; i++) {
			if (i % 2)
				a[i] = (a[i] - a[i + 1] + mod) % mod;
			else
				a[i] = (a[i] + a[i + 1]) % mod;
		}
		n--;
		a.pop_back();
	}
	long long fir = 0, sec = 0;
	long long is = 1;
	for (int i = 0; i < n; i+= 2) {
		fir = (((fir + is * a[i]) % mod) + mod) % mod;
		is = (is * ((n / 2) - 1 - (i / 2))) % mod;
		is = (is * back((i / 2) + 1)) % mod;
	}
	is = 1;
	for (int i = 1; i < n; i+= 2) {
		sec = (((sec + is * a[i]) % mod) + mod) % mod;
		is = (is * ((n / 2) - 1 - (i / 2))) % mod;
		is = (is * back((i / 2) + 1)) % mod;
	}
	if ((n / 2) % 2 == 0)
		cout << (((fir - sec + mod) % mod) + mod) % mod;
	else
		cout << (((fir + sec + mod) % mod) + mod) % mod;
	/*int st = 0;
	while (a.size() != 1) {
		for (int i = 0; i < n - 1; i++) {
			if (st % 2)
				a[i] = (a[i] - a[i + 1] + mod) % mod;
			else
				a[i] = (a[i] + a[i + 1]) % mod;
			st++;
		}
		n--;
		a.pop_back();
	}
	cout << '\n' << a[0];*/
	return 0;
}