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

const int N = 20005;
int n, T;
char s[N];

int main() {
	read(T);
	while (T--) {
		scanf ("%s", s + 1);
		n = strlen(s + 1);
		int cnt = 0;
		for (int i = 1;i <= n; i++) cnt += s[i] - '0';
		if (!cnt) {
			cout << 0 << endl;
			continue;
		}
		cnt = n - cnt;
		for (int i = 1;i <= n; i++) {
			if (s[i] == '1') break;
			cnt--;
		}
		for (int i = n;i >= 1; i--) {
			if (s[i] == '1') break;
			cnt--;
		}
		cout << cnt << endl;
	}
	return 0;
}