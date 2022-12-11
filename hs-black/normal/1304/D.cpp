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

const int N = 200505;
char s[N];
int cnt, n; 
int mx[N], mn[N];
int hi[N], T;
int main() {
	read(T);
	while (T--) { 
		read(n); scanf ("%s", s + 1);
		cnt = 0; s[0] = '<', s[n] = '>';
		for (int i = 1;i <= n; i++) 
			if (s[i-1] == '<' && s[i] == '>') hi[++cnt] = i; 
		int p = n;
		for (int i = 1;i <= cnt; i++) {
			mn[hi[i]] = p--;
			for (int j = hi[i]-1;j >= 1; j--) {
				if (s[j-1] == '>') break;
				mn[j] = p--;
			}
		}
		p = n;
		for (int i = cnt; i >= 1; i--) {
			mx[hi[i]] = p--;
			for (int j = hi[i]-1; j >= 1; j--) {
				if (s[j-1] == '>') break;
				mx[j] = p--;
			}
		}
		for (int i = 1;i <= cnt; i++) {
			for (int j = hi[i]+1;j <= n; j++) {
				mn[j] = mx[j] = p--;
				if (s[j] == '<') break;
			}
		}	
		for (int i = 1;i <= n; i++) 
			write(mn[i]), putchar(' ');
		putchar('\n');
		for (int i = 1;i <= n; i++) 
			write(mx[i]), putchar(' ');
		putchar('\n');
	}
	return 0;
}
/*
2
7 >><>><
5 >>><


*/