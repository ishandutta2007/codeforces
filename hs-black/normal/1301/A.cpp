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

const int N = 100000;
char a[N], b[N], c[N];
int main() {
	int T; read(T);
	while (T--) {
		scanf ("%s%s%s", a + 1, b + 1, c + 1);
		int n = strlen(a + 1), fl = 0;
		for (int i = 1;i <= n; i++) {
			if (a[i] == c[i] || b[i] == c[i]) continue;
			fl = 1; break;
		}
		if (fl) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}