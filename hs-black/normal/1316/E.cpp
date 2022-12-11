#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
 
template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}
 
template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}
 
const int N = 100500;
struct node {
	int p, a;
}t[N];
 
bool cmp(node a, node b) {
	return a.a > b.a;
}
 
 
ll s[N][9];
 
inline void Mx(ll &x, ll y) {
	if (x < y) x = y;
}
 
inline ll to(int x) {
	return 1 << (x - 1);
}
 
int siz[N], n, p, k;
ll f[500];
 
int main() {
	read(n), read(p), read(k);
	for (int i = 1;i <= n; i++) read(t[i].a), t[i].p = i;
	for (int i = 1;i <= n; i++) 
		for (int j = 1;j <= p; j++) read(s[i][j]);
	for (int i = 1;i <= 1000; i++) siz[i] += siz[i>>1] + (i & 1);
	sort(t + 1, t + n + 1, cmp);
	memset(f, -0x3f, sizeof(f));
	f[0] = 0;
	int all = (1 << p) - 1;
	for (int i = 1;i <= n; i++) {
		int x = t[i].p;
		if (i <= k)
		for (int j = all;j >= 0; j--) f[j] += t[i].a;
		for (int j = 1;j <= p; j++) {
			ll S = all ^ to(j), l = s[x][j];
			if (i <= k) l -= t[i].a - t[k+1].a;
			Mx(f[to(j)], f[0] + l);
			for (int g = S; g; g = (g - 1) & S) {
				l = s[x][j];
				if (i <= k + siz[g]) l -= t[i].a - t[k+siz[g]+1].a;
				Mx(f[g | to(j)], f[g] + l);
			}
		}
	}
	cout << f[all] << endl;
	return 0;
}