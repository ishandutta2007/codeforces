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

const int N = 5005;
char ans[N], s[N], tmp[N];
int n, t;
int main() {
	int T; read(T);
	while (T--) {
		read(n); scanf ("%s", s + 1);
		for (int i = 1;i <= n; i++) ans[i] = s[i];
		t = 1;
		for (int i = 1;i <= n; i++) {
			for (int j = i;j <= n; j++)
				tmp[j-i+1] = s[j];
			for (int j = 1;j < i; j++)
				tmp[n-j+1] = s[j];
			if ((n - i) & 1) reverse(tmp + n - i + 2, tmp + n + 1);
			for (int j = 1;j <= n; j++) {
				if (tmp[j] < ans[j]) {
					for (int k = 1;k <= n; k++) ans[k] = tmp[k];
					t = i; break;
				}
				if (tmp[j] > ans[j]) break;
			}
		}
		for (int i = 1;i <= n; i++) putchar(ans[i]);
		cout << endl << t << endl;
	}
	return 0;
}
/*
1
9
lfpbavjsm



*/