#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n')
{
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 500005;
int T, n, a[N], st[N], tp;
char s[N];

int main() {
	for (read(T); T; T--) {
		read(n); tp = 0;
		scanf ("%s", s + 1);
		for (int i = 1;i <= n; i++) 
			a[i] = s[i] - '0';
		scanf ("%s", s + 1);
		int l = 1, r = n, rev = 0;
		for (int i = n;i >= 2; i--) {
			int k = a[r], t = s[i] - '0';
			if (rev) k = !a[l];
			if (t != k) {
				if (rev) {
					int p = !a[r];
					if (p == t) st[++tp] = 1;
					st[++tp] = i, rev = 0, r--;
				}
				else {
					int p = a[l];
					if (p == t) st[++tp] = 1;
					st[++tp] = i, rev = 1, l++;
				}
			}
			else {
				if (rev) l++;
				else r--;
			}
		}
		int t = s[1] - '0', k = 0;
		if (rev) k = !a[l];
		else k = a[l];
		if (k != t) st[++tp] = 1;
		write(tp, ' ');
		for (int i = 1;i <= tp; i++)
			write(st[i], ' ');
		puts("");
	}
	return 0;
}