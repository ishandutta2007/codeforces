#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const int inf = 0x3f3f3f3f;
const ll linf = 1LL << 60;
const ld eps = 1e-9;
struct IO {
	static const int Siz = 32768;
	char ibuf[Siz], *ied = ibuf + Siz, *ipos = ied - 1;
	int getchar() {
		if (++ ipos == ied)
			ied = ibuf + fread(ipos = ibuf, 1, Siz, stdin);
		return ipos < ied ? *ipos : EOF;
	}
	char obuf[Siz], *oed = obuf + Siz, *opos = obuf;
	void flush() {
		fwrite(obuf, 1, opos - obuf, stdout);
		opos = obuf; fflush(stdout);
	}
	void putchar(int c) {
		*(opos ++) = c;
		if (opos == oed) flush();
	}
	~IO() {flush();}
} io;
#define getchar io.getchar
#define putchar io.putchar
template <typename T = int>
inline T read() {
	T x = 0;
	int f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
template <typename T>
inline void write(T x) {
	if (!x) {putchar('0'); return;}
	if (x < 0) putchar('-'), x = -x;
	int stk[20], tp = 0;
	for (; x; stk[tp ++] = x % 10, x /= 10);
	for (; tp; putchar(48 + stk[-- tp]));
}
int n;
int cnt1, cnt2;
int main() {
	n = read();
	for (int i = 0; i < n; ++ i) {
		int x = read();
		if (x == 1) cnt1 ++;
		else cnt2 ++;
	}
	if (cnt2) {
		printf("2 "); -- cnt2;
		if (cnt1) {
			printf("1 "); -- cnt1;
			while (cnt2 --) printf("2 ");
			while (cnt1 --) printf("1 ");
		} else {
			while (cnt2 --) printf("2 ");
		}
	} else {
		while (cnt1 --) printf("1 ");
	}
	return 0;
}