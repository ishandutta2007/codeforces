#include <queue>
#include <vector>
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

ll ans, d, m;
ll f[60][60], mi[60];

int main() {
	int T; read(T);
	while (T--) {
		memset(f, 0, sizeof(f));
		read(d), read(m); ll up, tmp = d;
		for (int i = 0;i <= 30; i++) {
			tmp >>= 1; if (!tmp) {up = i; break;}
		}
		f[0][0] = mi[1] = 1; ans = 0;
		for (int i = 2;i <= 30; i++) mi[i] = mi[i-1] * 2 % m;
		for (int i = 1;i <= up + 1; i++) {
			for (int j = i;j <= up + 1; j++) {
				for (int k = i - 1;k < j; k++) {
					if (j == up + 1) 
						(f[i][j] += f[i-1][k] * (d - (1 << up) + 1)) %= m;
					else (f[i][j] += f[i-1][k] * mi[j]) %= m;
				}
				(ans += f[i][j]) %= m;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
10
3 99
4 9999997
5 999996
6 99995
7 9994
8 993
9 92
10 1

*/