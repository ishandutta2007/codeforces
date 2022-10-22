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

int a[N];
int cnt[N];
int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int n, k; scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++ i) scanf("%d", &a[i]);
		int lb = 0, rb = 1e9;
		int ans = 0;
		auto chk = [&] (int md) {
			bool ok = 0;
			vector <int> v;
			for (int i = 0; i < n; ++ i) {
				v.pb(a[i] - md); v.pb(a[i] + md + 1);
			}
			sort(v.begin(), v.end());
			v.erase(unique(v.begin(), v.end()), v.end());
			int m = v.size();
			for (int i = 0; i < m; ++ i) cnt[i] = 0;
			for (int i = 0; i < n; ++ i) {
				cnt[lower_bound(v.begin(), v.end(), a[i] - md) - v.begin()] ++;
				cnt[lower_bound(v.begin(), v.end(), a[i] + md + 1) - v.begin()] --;
			}
			for (int i = 1; i < m; ++ i) cnt[i] += cnt[i - 1];
			for (int i = 0; i < m; ++ i) if (cnt[i] > k) {
				ok = 1, ans = v[i];
				break;
			}
			return ok;
		};
		for (; lb < rb; ) {
			int md = lb + rb >> 1;
			if (chk(md)) rb = md;
			else lb = md + 1;
		}
		chk(lb);
		printf("%d\n", ans);
	}
	return 0;
}