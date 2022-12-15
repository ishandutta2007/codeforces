
/*
 
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

const int N = 2205;
char s[N];
int st[N], cnt, tp, T, n;
int ch[N*9][10], f[N*9], ed[N*9];

void insert(void) {
	int p = 0;
	for (int i = 1;i <= tp; i++) {
		if (!ch[p][st[i]]) ch[p][st[i]] = ++cnt;
		p = ch[p][st[i]];
	}
	ed[p] = 1;
}

void build(void) {
	queue<int> q;
	for (int i = 1;i <= 9; i++) 
		if (ch[0][i]) q.push(ch[0][i]);
	while (q.size()) {
		int x = q.front(); q.pop();
		ed[x] |= ed[f[x]];
		for (int i = 1;i <= 9; i++) 
			if (ch[x][i]) f[ch[x][i]] = ch[f[x]][i], q.push(ch[x][i]);
			else ch[x][i] = ch[f[x]][i];
	}
}

void dfs(int nd, int S) {
	if (!nd) return insert();
	for (int i = 1;i <= 9 && i <= nd; i++) {
		int t = 0, fl = 0;
		for (int j = i;j < n; j++) {
			if (n % j) continue;
			t = j - i;
			if (S >> t & 1) {fl = 1; break; }
		}
		if (fl) continue;
		st[++tp] = i, dfs(nd - i, (S << i | 1) & T), tp--;
	}
}

int dp[N][N*3];
int main() {
	scanf ("%s", s + 1), read(n); 
	T = (1 << n) - 1, dfs(n, 1), build();
	int len = strlen(s + 1);
	for (int i = 1;i <= len; i++) {
		for (int j = 0;j <= cnt; j++)
			if (!ed[j]) dp[i][j] = dp[i-1][j] + 1;
		for (int j = 0;j <= cnt; j++) {
			if (ed[j]) continue;
			Mn(dp[i][ch[j][s[i]-'0']], dp[i-1][j]); 
		}
	}
	int ans = len;
	for (int i = 0;i <= cnt; i++)
		if (!ed[i]) Mn(ans, dp[len][i]);
	write(ans);
	return 0;
}

/*

*/