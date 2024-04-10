#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
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

const int N = 300;
int ans[N], n;
char s[N];

void dfs(int x) {
	for (int i = 1;i <= n; i++) {
		if (i == x) continue;
		if ((i < x && s[i] > s[x]) || (i > x && s[i] < s[x])) {
			if (ans[i] != ans[x]) {
				if (ans[i] == -1)
				ans[i] = ans[x] ^ 1, dfs(i);
			}
			else {
				cout << "NO\n";
				exit(0);
			}
		}
	}
}

int main() {
	read(n); scanf ("%s", s + 1);
	memset(ans, -1, sizeof(ans));
	for (int i = 1;i <= n; i++) 
	if (ans[i] == -1) ans[i] = 0, dfs(i);
//	ans[1] = 1; dfs(1);
	cout << "YES\n";
	for (int i = 1;i <= n; i++) {
		if (ans[i] == -1) ans[i] = 0;
		cout << ans[i];
	}
	cout << endl;
	return 0;
}