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

const int N = 100050;
int st[N][19], lg[N], a[N], c[N], n, q;
vector<int> v[N];

int gcd(int x, int y) { return !y ? x : gcd(y, x % y); }

int main() {
	read(n); lg[0] = -1;
	for (int i = 1;i <= n; i++)
		read(a[i]), c[i] = st[i][0] = a[i], lg[i] = lg[i>>1] + 1;
	sort(c + 1, c + n + 1); int m = unique(c + 1, c + n + 1) - c - 1; c[m + 1] = 0;
	for (int i = 1;i <= n; i++) v[lower_bound(c + 1, c + m + 1, a[i]) - c].push_back(i);
	for (int j = 1;j <= 20; j++) 
		for (int i = 1;i + (1 << j) - 1 <= n; i++)
			st[i][j] = gcd(st[i][j-1], st[i+(1<<(j-1))][j-1]);
	for (read(q); q; q--) {
		int l, r; read(l), read(r); int len = r - l + 1;
		int t = lg[len], G = gcd(st[l][t], st[r-(1<<t)+1][t]);
		int pos = lower_bound(c + 1, c + m + 1, G) - c;
		if (c[pos] != G) { write(len); continue; }
		l = lower_bound(v[pos].begin(), v[pos].end(), l) - v[pos].begin();
		r = upper_bound(v[pos].begin(), v[pos].end(), r) - v[pos].begin();
		write(len - (r - l));
	}
	return 0; 
}