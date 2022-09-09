#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int P = 998244353;

int norm(int x) { return x >= P ? x - P : x; }
void add(int& x, int y) { if ((x += y) >= P) x -= P; }

// int iabs(int x) { return x < 0 ? -x : x; }
// int sgn(int x) { return x < 0 ? -1 : 1; }

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		ll a, b, x; cin >> a >> b >> x;
		ll g = gcd(a, b);
		bool f = false;
		while (true) {
			if (x == a || x == b) { f = true; break; }
			if (a < b) swap(a, b);
			if (x > a) break;
			b = min(b, a - b);
			if (b == 0) break;
			if (x % b == a % b) { f = true; break; }
			a %= b;
		}
		cout << (f ? "YES\n" : "NO\n");
	}

	return 0;
}