#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n')
{
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 3e6+50;
const int P = 51123987;
char s[N]; int n;
int f[N], cnt = 1, las;
int len[N], dep[N]; 
int h[N], ne[N], to[N], w[N], tot;
inline void add(int x, int y, int z) {
	ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z;
}
int get(int x, int c) {
	for (int i = h[x]; i; i = ne[i])
		if (w[i] == c) return to[i];
	return 0;
}
struct Pam {
	int ans[N];
	int getfail(int x, int c) {
		while (s[c - len[x] - 1] != s[c]) x = f[x];
		return x;
	}
	
	int insert(int c, int x) {
		int p = getfail(las, x);
		if (!get(p, c)) {
			len[++cnt] = len[p] + 2, h[cnt] = 0;
			f[cnt] = get(getfail(f[p], x), c);
			add(p, cnt, c), dep[cnt] = dep[f[cnt]] + 1;
		}
		return dep[las = get(p, c)];
	}
	
	void work(void) {
		h[0] = h[1] = tot = 0;
		f[0] = f[1] = cnt = 1, len[1] = -1;
		for (int i = 1;i <= n; i++)
			ans[i] = insert(s[i] - 'a', i);
	}
}A, B;

int main() {
	read(n), scanf ("%s", s + 1);
	A.work(), reverse(s + 1, s + n + 1), B.work();
	for (int i = 1;i <= n; i++)
		A.ans[i] = (A.ans[i] + A.ans[i-1]) % P;
	ll ans = 0, sum = A.ans[n];
	for (int i = 1;i <= n; i++)
		ans += (ll)A.ans[i] * B.ans[n - i], ans %= P;
	sum = sum * (sum - 1) / 2;
	write(((sum - ans) % P + P) % P);
	return 0;
}