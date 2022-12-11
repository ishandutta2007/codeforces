
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

const int N = 2005000;
int prime[N], ap[N], e[N], tot;
void prework(int lim) {
	for (int i = 2;i <= lim; i++) {
		if (!e[i]) prime[++tot] = e[i] = i;
		for (int j = 1;j <= tot && prime[j] * i <= lim; j++) {
			int t = prime[j] * i; e[t] = prime[j];
			if (prime[j] == e[i]) break;
		}
		ap[i] += (e[i] == i) + ap[i-1];
		if (e[i] == i && (ll)i * i <= 1000000) ap[i * i]--;
	}
}

int t, n;
int main() {
	prework(1e6);
	for (read(t); t; t--) 
		read(n), write(ap[n] + 1);
	return 0;
}