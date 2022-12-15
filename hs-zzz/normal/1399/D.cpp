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

const int N = 300500;
char s[N];
int n, T;
int s0[N], s1[N], t0, t1, cnt;
int a[N];
int main() {
	for (read(T); T; T--) {
		read(n), scanf ("%s", s + 1);
		t0 = t1 = cnt = 0;
		for (int i = 1;i <= n; i++) {
			if (s[i] == '0') {
				if (t1) s0[++t0] = s1[t1], t1--;
				else cnt++, s0[++t0] = cnt;
				a[i] = s0[t0];
			}
			else {
				if (t0) s1[++t1] = s0[t0], t0--;
				else cnt++, s1[++t1] = cnt;
				a[i] = s1[t1];
			}
		}
		write(cnt);
		for (int i = 1;i <= n; i++) write(a[i], ' ');
		puts("");
	}
	return 0;
}