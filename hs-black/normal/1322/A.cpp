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
const int N = 1e6+5;
char s[N];
int n, s1, m1, l;
int main() {
	read(n);
	scanf ("%s", s + 1);
	int ans = 0;
	for (int i = 1;i <= n; i++) {
		if (s[i] == ')') s1++;
		else s1--;
		if (s1 == 0 && l) ans += (i - l + 1), l = 0;
		if (s1 > 0 && l == 0) l = i;
	}
	if (s1 != 0) {
		puts("-1");
		return 0;
	}
	printf ("%d\n", ans);
	return 0;
}