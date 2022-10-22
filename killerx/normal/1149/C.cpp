#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int inf = 0x3f3f3f3f;
const ll linf = 1LL << 60;
struct IO {
	static const int Siz = 1 << 13;
	char ibuf[Siz], *ied = ibuf + Siz, *ipos = ied - 1;
	int getchar() {
		if (++ ipos == ied) ied = ibuf + fread(ipos = ibuf, 1, Siz, stdin);
		return ipos < ied ? *ipos : EOF;
	}
	void gets(char * s) {
		char c = getchar();
		for (; isspace(c); c = getchar());
		for (;!isspace(c); c = getchar()) *(s ++) = c;
	}
	char obuf[Siz], *oed = obuf + Siz, *opos = obuf;
	void flush() {fwrite(obuf, 1, opos - obuf, stdout); opos = obuf; fflush(stdout);}
	void putchar(int c) {*(opos ++) = c; if (opos == oed) flush();}
	void puts(const char * s) {for (; *s; putchar(*(s ++))); putchar('\n');}
	~IO() {flush();}
} io;
#define getchar io.getchar
#define putchar io.putchar
#define gets io.gets
#define puts io.puts
template <typename T>
inline void read(T & x) {
	x = 0;  int f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	if (!f) x = -x;
}
template <typename T>
inline void write(T x) {
	if (!x) {putchar('0'); return;}
	if (x < 0) putchar('-'), x = -x;
	int stk[20], tp = 0;
	for (; x; stk[tp ++] = x % 10, x /= 10);
	for (; tp; putchar(48 + stk[-- tp]));
}
const int N = 1 << 18;
int n, q;
char s[N];
struct SegT {
	struct T {
		int dep, mndep, mxdep;
		int mxl, mxr, ans;
	} t[N << 1];
	T newNode(char c) {
		if (c == '(')
			return (T) {1, 0, 1, 0, 1, 1};
		else
			return (T) {-1, -1, 0, 2, 1, 1};
	}
	T pu(T x, T y) {
		T ans;
		ans.dep = x.dep + y.dep;
		ans.mndep = min(x.mndep, x.dep + y.mndep);
		ans.mxdep = max(x.mxdep, x.dep + y.mxdep);
		ans.mxl = max(x.mxl, max(y.mxl - x.dep, x.mxdep - 2 * (y.mndep + x.dep)));
		ans.mxr = max(x.mxr, max(y.mxr - x.dep, (y.mxdep + x.dep) - 2 * x.mndep));
		ans.ans = max(x.ans, max(y.ans, max(x.mxl + y.mxdep + x.dep, x.mxdep + y.mxr - x.dep)));
		return ans;
	}
	void upd(int x, T v) {
		t[x += N] = v;
		for (x >>= 1; x; x >>= 1) {
			t[x] = pu(t[x << 1], t[x << 1 | 1]);
		}
	}
	int qry() {
		return t[1].ans;
	}
} segt;
int main() {
	read(n); read(q); gets(s);
	for (int i = 0; i < n + n - 2; ++ i) {
		segt.upd(i, segt.newNode(s[i]));
	}
	write(segt.qry()), putchar('\n');
	for (; q --; ) {
		int a, b;
		read(a); read(b);
		-- a; -- b;
		segt.upd(a, segt.newNode(s[b]));
		segt.upd(b, segt.newNode(s[a]));
		swap(s[a], s[b]);
		write(segt.qry()), putchar('\n');
	}
	return 0;
}