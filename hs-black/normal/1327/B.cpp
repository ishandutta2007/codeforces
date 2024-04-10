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

const int N = 100500;
ll T, n, m, k;
int c[N], fl[N], vis[N];
vector<int> v[N];

int main() {
	read(T);
	while (T--) {
		read(n); k = 0;
		for (int i = 1;i <= n; i++) {
			read(c[i]); int x; v[i].clear();
			vis[i] = fl[i] = 0;
			for (int j = 1;j <= c[i]; j++)
				read(x), v[i].push_back(x);
		}
		for (int i = 1;i <= n; i++) {
			for (auto j: v[i])
				if (!vis[j]) { vis[j] = 1; fl[i] = 1; break; }
			if (!fl[i]) k = 1;
		}
		if (!k) puts("OPTIMAL");
		else {
			puts("IMPROVE");
			int i = n;
			for (i = n;i >= 1; i--) if (!fl[i]) break;
			for (int j = 1;j <= n; j++) if (!vis[j]) {
				printf ("%d %d\n", i, j); break; }
		}
	}
	return 0;
}