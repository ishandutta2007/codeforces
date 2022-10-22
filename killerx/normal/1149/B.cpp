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
#ifndef DEBUG
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
#endif
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
const int N = 1e5 + 5;
const int L = 255;
int n, q;
char s[N];
int dp[L][L][L];
int nxt[N][26];
vector <char> str[3];
int main() {
	n = read(), q = read();
	for (int i = 0; i < n; ++ i) s[i] = getchar();
	for (int i = 0; i < 26; ++ i) nxt[n][i] = n;
	for (int i = n - 1; ~i; -- i) {
		for (int j = 0; j < 26; ++ j) nxt[i][j] = nxt[i + 1][j];
		nxt[i][s[i] - 'a'] = i;
	}
	dp[0][0][0] = -1;
	while (q --) {
		char c = getchar();
		while (isspace(c)) c = getchar();
		int i = read() - 1;
		if (c == '+') {
			c = getchar();
			str[i].PB(c);
			for (int a = 0; a <= (i == 0 ? str[1].size() : str[0].size()); ++ a) {
				for (int b = 0; b <= (i <= 1 ? str[2].size() : str[1].size()); ++ b) {
					int & v = (i == 0 ? dp[str[i].size()][a][b] : (i == 1 ? dp[a][str[i].size()][b] : dp[a][b][str[i].size()]));
					int u1 = (i == 0 ? dp[str[i].size() - 1][a][b] : (i == 1 ? dp[a][str[i].size() - 1][b] : dp[a][b][str[i].size() - 1]));
					int u2 = !a ? n : (i == 0 ? dp[str[i].size()][a - 1][b] : (i == 1 ? dp[a - 1][str[i].size()][b] : dp[a - 1][b][str[i].size()]));
					int u3 = !b ? n : (i == 0 ? dp[str[i].size()][a][b - 1] : (i == 1 ? dp[a][str[i].size()][b - 1] : dp[a][b - 1][str[i].size()]));
					v = n;
					if (u1 < n) v = min(v, nxt[u1 + 1][str[i].back() - 'a']);
					if (u2 < n) v = min(v, nxt[u2 + 1][(i == 0 ? str[1][a - 1] : str[0][a - 1]) - 'a']);
					if (u3 < n) v = min(v, nxt[u3 + 1][(i <= 1 ? str[2][b - 1] : str[1][b - 1]) - 'a']);
				}
			}
//			for (int a = 0; a <= str[0].size(); ++ a) {
//				for (int b = 0; b <= str[1].size(); ++ b) {
//					for (int c = 0; c <= str[2].size(); ++ c) {
//						cerr << "dp " << a << " " << b << " " << c << ": " << dp[a][b][c] << endl;
//					}
//				}
//			}
		} else str[i].pop_back();
		if (dp[str[0].size()][str[1].size()][str[2].size()] == n) puts("NO");
		else puts("YES");
	}
	return 0;
}