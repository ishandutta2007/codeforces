// Code by Denverjin.
#include <bits/stdc++.h>
using namespace std;

using ld = double;
using ll = long long;
using ull = unsigned long long;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;

const int SZ = 1 << 13;
char buff[SZ], *pos = buff + SZ - 1;
#define getchar() (++ pos == buff + SZ ? fread(pos = buff, 1, SZ, stdin), *pos : *pos)

inline ll read() {
	ll x = 0; int f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48);
	return x * f;
}

const int A[] = {
1,
1,
5,
1,
21,
1,
85,
73,
341,
89,
1365,
1,
5461,
4681,
21845,
1,
87381,
1,
349525,
299593,
1398101,
178481,
5592405,
1082401
};
bool chk(int x) {while (x > 1) {if (x & 1) return 0;x >>= 1;}return 1;}
int cal(int x) {int cnt = 0;while (x > 1) x >>= 1, ++ cnt;return cnt;}
int main() {
	int q = read();
	while (q --) {
		int a = read();
		if (chk(a + 1)) {
			printf("%d\n", A[cal(a + 1) - 2]);
		}
		else {
			int b = 0;
			for (int i = 0; ; ++ i) {
				int nb = b;
				if (!(a >> i & 1)) nb = b | 1 << i;
				if (nb >= a) break;
				b = nb;
			}
			printf("%d\n", __gcd(a & b, a ^ b));
		}
	}
	return 0;
}