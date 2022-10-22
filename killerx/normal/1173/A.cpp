#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
#define pb push_back
#define mp make_pair
using ll = long long;
using vi = vector <int>;
using pii = pair <int, int>;
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (auto it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == 45) f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - 48;
	return f ? x : -x;
}

char sgn(int x) {
	return x > 0 ? '+' : x < 0 ? '-' : '0';
}
int main() {
	int x, y, z;
	x = read(), y = read(), z = read();
	if (sgn(x - y - z) != sgn(x - y + z)) putchar('?');
	else putchar(sgn(x - y + z));
	return 0;
}