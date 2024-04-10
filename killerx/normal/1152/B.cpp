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
vector <int> v;
bool chk(int n) {
	return __builtin_popcount(n + 1) == 1;
}
int main() {
	int n = read();
	int ans = 0;
	while (!chk(n)) {
		int i = 32 - __builtin_clz(n);
		while (n & 1 << i - 1) -- i;
		v.PB(i);
		n ^= (1 << i) - 1; ++ ans;
		if (chk(n)) break;
		++ n; ++ ans;
	}
	write(ans); putchar('\n');
	for (int i = 0; i < (int) v.size(); ++ i) {
		write(v[i]); putchar(i + 1 == (int) v.size() ? '\n' : ' ');
	}
	return 0;
}