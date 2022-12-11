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

const int N = 150;
char s[N][N];
int n, m;

bool check(char *a, char *b) {
	for (int i = 1;i <= m; i++) 
		if (a[i] != b[m-i+1]) return false;
	return true;
}

bool vis[N];
int sta[N], stb[N], ans;
int main() {
	read(n), read(m);
	for (int i = 1;i <= n; i++) scanf ("%s", s[i] + 1);
	bool tmp = 0; int k;
	for (int i = 1;i <= n; i++) {
		for (int j = 1;j < i; j++) {
			if (vis[j]) continue;
			if (check(s[i], s[j])) {
				sta[++ans] = i, stb[ans] = j;
				vis[i] = 1; break;
			}
		}
	}
	for (int i = 1;i <= n; i++) {
		if (!vis[i] && check(s[i], s[i])) {
			tmp = 1, k = i; break;
		}
	}
	cout << (ans * 2 + tmp) * m << endl;
	for (int i = 1;i <= ans; i++) printf ("%s", s[sta[i]] + 1);
	if (tmp) printf ("%s", s[k] + 1);
	for (int i = ans;i >= 1; i--) printf ("%s", s[stb[i]] + 1);
	return 0;
}