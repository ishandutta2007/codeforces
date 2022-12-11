#pragma GCC optimize(3, "inline")
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
inline void write(F x)
{
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar('\n');
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 200050;
const int K = 400;
int T[1505][17000], tag[1505], w[N], Ty, n, k, q;

int a[N], b[N], c[N], ans, cnt;
void build1(void) {
	for (int i = 1;i <= n; i++) {
		if (i > k) w[i] = w[i-k] ^ c[i];
		else w[i] = c[i];
		if (w[i]) ans++, i + k > n && cnt++;
	}
}

int L[1505], num[1505], bl[N], bls;
void build2(void) {
	for (int i = 1;i <= k; i++) {
		int pre = 0, l, r; num[i] = bls + 1;
		for (l = i, r = l + K * k - 1; l <= n; l += K * k, r += K * k) {
			L[++bls] = i; Mn(r, n);
			for (int p = l; p <= r ; p += k) 
				(pre = (w[p] = pre ^ c[p])) && ans++, T[bl[p] = bls][pre]++;
		}
		if (pre) cnt++;
	} num[k+1] = bls + 1;
}

void change1(int p, int x) {
	for ( ; p <= n ; p += k)
		!w[p] && ans++, !(w[p] ^= x) && ans--;
	!w[p-k] && cnt--, w[p-k] == x && cnt++;
}

void change2(int p, int x) {
	int t = (p - 1) % k + 1;
	for (int i = p; bl[p] == bl[i]; i += k) {
		!(w[i] ^ tag[bl[p]]) && ans++;
		T[bl[p]][w[i]]--, w[i] ^= x, T[bl[p]][w[i]]++;
		!(w[i] ^ tag[bl[p]]) && ans--;
	}
	for (int i = bl[p] + 1; L[i] == t; i++)
		ans += T[i][tag[i]], tag[i] ^= x, ans -= T[i][tag[i]];
	int tp = (n - 1) / k * k + t; tp > n && (tp -= k);
	!(w[tp] ^ tag[num[t+1]-1]) && cnt--;
	(w[tp] ^ tag[num[t+1]-1]) == x && cnt++;
}

void update(int p, int x) {
	if (x == c[p]) return; c[p] ^= (x ^= c[p]);
	Ty ? change1(p, x) : change2(p, x);
}

int main() {
//	freopen ("hs.in","r",stdin);
//	freopen ("hs.out","w",stdout);
	read(n), read(k), read(q); Ty = ((n/k+1) <= K);
	for (int i = 1;i <= n; i++) read(a[i]);
	for (int i = 1;i <= n; i++) 
		read(b[i]), c[i] = a[i] ^ b[i] ^ a[i-1] ^ b[i-1];
	n++, c[n] = a[n-1] ^ b[n-1]; Ty ? build1() : build2();
	write(cnt ? -1 : ans);
	while (q--) {
		char s[5]; scanf ("%s", s); 
		int p, v; read(p), read(v);
		s[0] == 'a' ? a[p] = v : b[p] = v;
		update(p, (a[p] ^ a[p-1]) ^ (b[p] ^ b[p-1]));
		update(p+1, (a[p] ^ a[p+1]) ^ (b[p] ^ b[p+1]));
		write(cnt ? -1 : ans);
	}
	return 0;
}