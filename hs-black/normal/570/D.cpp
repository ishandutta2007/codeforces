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

const int N = 1000050;
vector<int> v[N], s[N];
int L[N], R[N], dep[N], num;
char str[N];
int h[N], ne[N<<1], to[N<<1], tot;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}
void dfs(int x, int fa) {
	dep[x] = dep[fa] + 1, L[x] = ++num;
	int pre = s[dep[x]].back();
	v[dep[x]].push_back(L[x]);
	s[dep[x]].push_back((1 << (str[x]-'a')) ^ pre);
	for (int i = h[x]; i; i = ne[i]) dfs(to[i], x);
	R[x] = num;
}

int ans, m, n;
int main() {
	read(n), read(m);
	for (int i = 2, x;i <= n; i++) read(x), add(x, i);
	scanf ("%s", str + 1);
	for (int i = 1;i <= n; i++) s[i].push_back(0), v[i].push_back(0);
	dfs(1, 0);
	while (m--) {
		int x, y; read(x), read(y);
		int l = lower_bound(v[y].begin(), v[y].end(), L[x]) - v[y].begin() - 1;
		int r = upper_bound(v[y].begin(), v[y].end(), R[x]) - v[y].begin() - 1;
		ans = s[y][r] ^ s[y][l];
		if (ans - (ans & -ans) == 0) puts("Yes");
		else puts("No");
	}
	return 0;
}