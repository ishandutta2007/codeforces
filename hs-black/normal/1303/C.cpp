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

const int N = 100;
int T, l, r, n;
int ans[N], now;
int vis[150];
char s[500];

int main() {
	read(T);
	while (T--) {
		memset(ans, 0, sizeof(ans));
		memset(vis, 0, sizeof(vis));
		int fl = 0;
		scanf ("%s", s + 1); n = strlen(s + 1);
		l = r = now = 50; vis[ans[l] = s[1]] = 1;
		for (int i = 2;i <= n; i++) {
			if (ans[now-1] == s[i]) {
				now--; continue;
			}
			if (ans[now+1] == s[i]) {
				now++; continue;
			}
			if (vis[s[i]]) {
				fl = 1; break;
			}
			if (now == l) {
				now = l = l - 1;
				vis[ans[l] = s[i]] = 1;
				continue;
			}
			if (now == r) {	
				now = r = r + 1;
				vis[ans[r] = s[i]] = 1;
				continue;
			}
			fl = 1; break;
		}
		if (fl) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (int i = l;i <= r; i++) 
			printf ("%c", ans[i]);
		for (int i = 'a';i <= 'z'; i++) 
			if (!vis[i]) printf ("%c", i);
		putchar('\n');
	}
	return 0;
}