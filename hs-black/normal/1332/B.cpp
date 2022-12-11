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

template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 10052;
int e[N], prime[N], tot;
int vis[20], col[N];
int main() {
	for (int i = 2;i <= 100; i++) {
		if (!e[i]) e[i] = i, prime[++tot] = i;
		for (int j = 1;j <= tot && prime[j] * i <= 100; j++) {
			e[prime[j] * i] = prime[j];
			if (prime[j] == e[i]) break;
		}
	}
	int T; read(T);
	while (T--) {
		int n; read(n); memset(vis, 0, sizeof(vis));
		int cnt = 0;
		for (int i = 1;i <= n; i++) {
			int a; read(a);
			for (int j = 1;j <= 11; j++) {
				if (a % prime[j] == 0) {
					if (!vis[j]) vis[j] = ++cnt;
					col[i] = vis[j]; break;
				}
			}
		}
		printf ("%d\n", cnt);
		for (int i = 1;i <= n; i++) printf ("%d ", col[i]);
		puts("");
	}
	return 0;
}