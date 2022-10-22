#pragma GCC optimize(2)
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define rep(i, n) for (int i = 0; i < n; ++ i)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const int inf = 0x3f3f3f3f;
const ll linf = 1LL << 60;
const ld eps = 1e-9;
int read() {
	int x = 0, f = 1, c = getchar();
	for(;!isdigit(c); c = getchar()) if(c == '-') f ^= 1;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	return f ? x : -x;
}
void write(int x) {
	if (!x) {putchar('0'); return;}
	if (x < 0) putchar('-'), x = -x;
	int stk[10], tp = 0;
	for (; x; x /= 10) stk[tp ++] = x - x / 10 * 10;
	for (; tp; putchar(48 + stk[-- tp]));
}
ll lcm(int a, int b) {return 1LL * a * b / __gcd(a, b);}
int main() {
	int a = read(), b = read();
	if (a > b) swap(a, b);
	int c = b - a;
	ll ans = lcm(a, b);
	int k = 0;
	vector <int> v;
	for (int i = 1; 1LL * i * i <= c; ++ i) if (c % i == 0) v.PB(i), v.PB(c / i);
	sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < (int) v.size(); ++ i) {
		int na = (a + v[i] - 1) / v[i] * v[i];
		int nb = (b + v[i] - 1) / v[i] * v[i];
		ll v = lcm(na, nb);
		if (v < ans || (v == ans && k > na - a)) ans = v, k = na - a;
	}
	write(k);
	return 0;
}