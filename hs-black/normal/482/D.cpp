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

const int N = 200500;
const int P = 1e9 + 7;
vector<int> vec[N];
inline void Add(int x, int y) { vec[x].push_back(y); }
inline void add(int &x, int y) { x += y, x >= P && (x -= P); }

int dp[N][2];
void dfs(int x) {
	dp[x][0] = dp[x][1] = 0;
	for (auto y: vec[x]) dfs(y), dp[y][0]++;
	int siz = vec[x].size();
	if (!siz) return dp[x][1] = 1, void();
	static int f[N][2];
	f[0][0] = 1, f[0][1] = 0;
	for (int i = 0;i < siz; i++) {
		int y = vec[x][i];
		f[i + 1][0] = (1ll * f[i][0] * dp[y][0] + 1ll * f[i][1] * dp[y][1]) % P;
		f[i + 1][1] = (1ll * f[i][0] * dp[y][1] + 1ll * f[i][1] * dp[y][0]) % P;
	}
	dp[x][1] = (dp[x][1] + 2 * f[siz][0]) % P;
	dp[x][0] = (dp[x][0] + 2 * f[siz][1]) % P;
	int t1 = 1, t2 = 1, t3 = 0;
	for (int i = 0;i < siz; i++) {
		int y = vec[x][i]; 
		t1 = 1ll * t1 * dp[y][0] % P;
		int tt2 = t2, tt3 = t3;
		t2 = (tt2 + 1ll * tt3 * dp[y][1]) % P;
		t3 = (tt3 + 1ll * tt2 * dp[y][1]) % P;
	}
	dp[x][1] = (dp[x][1] - t1 + P) % P;
	dp[x][0] = (dp[x][0] - t3 + P) % P;
}

int T, n;
int main() {
//	freopen ("hs.in","r",stdin);
//	for (read(T); T; T--) {
		read(n);
		for (int i = 1;i <= n; i++) vec[i].clear();
		for (int i = 2, x;i <= n; i++) read(x), Add(x, i);
		dfs(1), write((dp[1][0] + dp[1][1]) % P);
//	}
	return 0;
}

/*

1
3 
1 1

4
1 2 1

*/