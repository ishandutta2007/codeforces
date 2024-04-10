/*
    ___                         ______      __                  __
   /   |____  __  ___________ _/ ____/___ _/ /___  ____  ______/ /____
  / /| /_  / / / / / ___/ __ `/ /   / __ `/ __/ / / / / / / __  / ___/
 / ___ |/ /_/ /_/ (__  ) /_/ / /___/ /_/ / /_/ /_/ / /_/ / /_/ (__  )
/_/  |_/___/\__,_/____/\__,_/\____/\__,_/\__/\__, /\__, /\__,_/____/
                                            /____//____/

 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)


*/

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
inline void write(F x, char ed = '\n') {
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

const int N = 1000500;
int ch[N][26], h[N], ne[N<<1], to[N<<1], tot, L[N], R[N], num, n;
inline void add(int x, int y) { ne[++tot] = h[x], to[h[x] = tot] = y; }
void dfs(int x) {
	L[x] = ++num;
	for (int i = h[x]; i; i = ne[i]) dfs(to[i]);
	R[x] = num;
}
int ed[N], len[N], las[N], f[N], cnt, ans;
char s[N];
vector<int> vec[N];
int main() {
	read(n);
	for (int i = 1, len;i <= n; ++i) {
		scanf ("%s", s + 1), len = strlen(s + 1);
		int p = 0;
		for (int j = 1;j <= len; ++j) {
			int c = s[j] - 'a';
			if (!ch[p][c]) ch[p][c] = ++cnt;
			p = ch[p][c];
			vec[i].push_back(p);
		}
		ed[las[p] = i] = p, ::len[i] = len;
	}
	queue<int> q;
	for (int i = 0;i < 26; ++i)
		if (ch[0][i]) q.push(ch[0][i]);
	while (q.size()) {
		int x = q.front(); q.pop();
		las[x] = las[x] ? las[x] : las[f[x]];
		add(f[x], x);
		for (int i = 0;i < 26; ++i)
			if (ch[x][i]) f[ch[x][i]] = ch[f[x]][i], q.push(ch[x][i]);
			else ch[x][i] = ch[f[x]][i];
	}
	dfs(0);
	static int d[N], vis[N], tim[N];
	auto add = [&](int x, int c) { for (; x <= num; x += x & -x) d[x] += c; };
	auto sum = [&](int x) { int res = 0; for (; x; x -= x & -x) res += d[x]; return res; };
	for (int i = 1;i <= n; ++i) {
		int lef = 1145141919;
		for (int j = len[i] - 1;j >= 0; --j) {
			int t = vec[i][j];
			add(L[t], 1);
			int x = las[t];
			if (x == i) x = las[f[t]];
			int tl = j - len[x] + 1;
			if (tl >= lef) continue;
			lef = tl;
			if (vis[x] != i) vis[x] = i, tim[x] = 0;
			++tim[x];
		}
		for (auto t: vec[i]) {
			int x = las[t];
			if (x == i) x = las[f[t]];
			if (!x || vis[x] == -1) continue;
			int nd = ed[x];
			if (sum(R[nd]) - sum(L[nd] - 1) == tim[x]) ++ans;
			vis[x] = -1;
		}
		for (auto t: vec[i]) add(L[t], -1);
	}
	write(ans);
	return 0;
}