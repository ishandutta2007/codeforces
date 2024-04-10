
/*
 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)

 */

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
inline void write(F x, char ed = '\n') {
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

const int N = 200500;
int a[N], n, L, T;
int main() {
	for (read(T); T; T--) {
		read(n), read(L);
		for (int i = 1;i <= n; i++) read(a[i]); a[0] = 0, a[n+1] = L;
		double t1 = 0, t2 = 0; int l = 0, r = n + 1, s1 = 1, s2 = 1;
		while (1) {
			if (l + 1 == r) {
				double s = a[r] - a[l];
				if (t1 < t2) {
					s -= s1 * (t2 - t1);
					t2 += s / (s1 + s2);
					printf ("%.10lf\n", t2);
					break;
				}
				else {
					s -= s2 * (t1 - t2);
					t1 += s / (s1 + s2);
					printf ("%.10lf\n", t1);
					break;
				}
			}
			double tt1 = (double)(a[l+1] - a[l]) / s1;
			double tt2 = (double)(a[r] - a[r-1]) / s2;
			if (tt1 + t1 <= tt2 + t2) t1 += tt1, s1++, l++;
			else t2 += tt2, s2++, r--;
		}
	}
	return 0;
}

/*

1
5 7
1 2 3 4 6

*/