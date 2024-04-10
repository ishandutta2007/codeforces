/*

 
| _ _|
 ` _x 
  /  |
 /  c ?
| |||
| (c_c_)_)


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

int main() {
	int T, n, k;
	for (read(T); T; T--) {
		read(n), read(k);
		if (k == n - 1) { 
			if (n == 4) { puts("-1"); continue;  }
			write(n - 1, ' '), write(n - 3);
			for (int i = 3;i < n - 1; ++i) {
				if (i * 2 >= n) break;
				write(i, ' '), write(i ^ (n - 1));
			}
			write(2, ' '), write(n - 2);
			write(1, ' '), write(0);
			continue;
		}
		write(n - 1, ' '), write(k);
		for (int i = 1;i < n - 1; ++i) {
			if (i * 2 >= n) break;
			if (i == k || (i ^ (n - 1)) == k) continue;
			write(i, ' '), write(i ^ (n - 1));
		}
		if (k) write(k ^ (n - 1), ' '), write(0);
	}
	return 0;
}