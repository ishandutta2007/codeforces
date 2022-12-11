
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

const int N = 5005;
int dp[N][N][2], n, a[N];
int main() {
	read(n);
	for (int i = 1;i <= n; i++) read(a[i]);
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0][0] = 0; a[0] = 1e9;
	for (int i = 1;i <= n; i++) {
		for (int j = 0;j + j <= i; j++) {
			if (i == 1) dp[i][j+1][1] = dp[i-1][j][0];
			else {
				Mn(dp[i][j+1][1], dp[i-2][j][1] + max(0, a[i-1] - min(a[i], a[i-2]) + 1));
				Mn(dp[i][j+1][1], dp[i-2][j][0] + max(0, a[i-1] - a[i] + 1));
			}
			dp[i][j][0] = min(dp[i-1][j][0], dp[i-1][j][1] + max(0, a[i] - a[i-1] + 1));
		}
	}
	n++;
	for (int i = 1;i + i <= n; i++)
		write(min(dp[n-1][i][0], dp[n-1][i][1]), ' ');
	return 0;
}