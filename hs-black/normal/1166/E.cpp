
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

#include <bitset>
const int N = 10050;
bitset<N> bit[N];
int m, n, k, x;
int main() {
	read(m), read(n);
	for (int i = 1;i <= m; i++) {
		read(k);
		for (int j = 1;j <= k; j++) 
			read(x), bit[i].set(x);
	}
	for (int i = 1;i <= m; i++) 
		for (int j = 1;j < i; j++) 
			if ((bit[i] & bit[j]).none()) 
				return puts("impossible"), 0;
	return puts("possible"), 0;
}