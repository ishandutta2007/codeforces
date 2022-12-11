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

const int N = 1005000;
int dp[N][3][3], cnt[N];
int n, x, mx;

inline void Mx(int &x, int y) {
	if (x < y) x = y;
}

int main() {
	memset(dp, -9, sizeof(dp));
	read(n), read(mx);
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i++) 
		read(x), cnt[x]++;
	for (int i = 1; i <= mx; i++) {
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 3; b++) {
				for (int c = 0; c < 3; c++) {
					int sum = a + b + c;
					if (sum > cnt[i]) continue;
					Mx(dp[i][b][c], dp[i-1][a][b] + (cnt[i] - sum) / 3 + c);
				}
			}
		}
	}
	cout << dp[mx][0][0] << endl;
	return 0;
}