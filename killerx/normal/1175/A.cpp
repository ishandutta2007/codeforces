#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define inf 0x3f3f3f3f
#define mod 1000000007
#define vi vector <int>
#define vpii vector <pii>
#define pii pair <int, int>
#define dbg(x) cerr << #x << " = " << x << endl
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)
#define fio(fn) freopen(fn".in", "r", stdin), freopen(fn".out", "w", stdout)

struct IO {
	static const int Siz = 1 << 13;
	char ibuf[Siz], *ips = ibuf + Siz - 1;
	char obuf[Siz], *ops = obuf;
	~IO() {o();}
	void i() {fread(ibuf, 1, Siz, stdin); ips = ibuf;}
	void o() {fwrite(obuf, 1, ops - obuf, stdout); ops = obuf;}
	void flush() {o(); fflush(stdout);}
	int getchar() {if (ips == ibuf + Siz - 1) i(); return *ips ++;}
	void putchar(int x) {if (ops == obuf + Siz) o(); *ops ++ = x;}
	void gets(char * s) {for (; !isspace(*s ++ = getchar()); );}
	void puts(char * s) {for (; *s; putchar(*s ++));}
} io;

#define getchar io.getchar
#define putchar io.putchar
#define gets io.gets
#define puts io.puts

int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == 45) f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - 48;
	return f ? x : -x;
}

void write(int x) {
	int stk[20], tp = 0;
	if (x < 0) putchar(45), x = -x;
	if (!x) putchar(48);
	for (; x; stk[tp ++] = x % 10, x /= 10);
	for (; tp; putchar(48 + stk[-- tp]));
}

#define N 1 << 20

int main() {
	int t; scanf("%d", &t);
	while (t --) {
		ll n, k; scanf("%lld%lld", &n, &k);
		ll ans = 0;
		while (n) {
			ans += n % k;
			n -= n % k;
			while (n && n % k == 0) {
				ans ++;
				n /= k;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}