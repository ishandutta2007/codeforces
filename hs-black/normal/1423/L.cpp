
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

#define ull unsigned ll
#include<tr1/unordered_map>
using namespace std::tr1;
unordered_map<ull, int> mp;

const int N = 2000500;
int n, s, d;
ull val[N], v[N], tv[N]; int siz[N];
int main() {
	read(n), read(s), read(d);
	for (int i = 1;i <= n; i++)
		val[i] = (ull)rand() * rand() * rand() * rand();
	for (int i = 1, sz, t;i <= s; i++) {
		read(sz); 
		for (int j = 1;j <= sz; j++)
			read(t), tv[i] ^= val[t];
	}
	
	int s1 = min(s >> 1, 10), s2 = s - s1;
	int t1 = (1 << s1) - 1, t2 = (1 << s2) - 1;
	for (int i = 1;i <= (1 << 20); i++) 
		siz[i] = siz[i>>1] + (i & 1);
	for (int i = 0;i <= t1; i++) 
		for (int q = 0;q < s1; q++)
			if (i & (1 << q)) v[i] ^= tv[q+1];
	for (int i = 0;i <= t2; i++) {
		ull tp = 0;
		for (int q = 0;q < s2; q++)
			if (i & (1 << q)) tp ^= tv[q+s1+1];
		if (mp.find(tp) != mp.end()) Mn(mp[tp], siz[i]);
		else mp[tp] = siz[i];
	}
	for (int i = 1, sz, t;i <= d; i++) {
		read(sz); ull tp = 0;
		for (int j = 1;j <= sz; j++) 
			read(t), tp ^= val[t];
		int ans = 10000;
		for (int j = 0;j <= t1; j++) 
			if (mp.find(tp ^ v[j]) != mp.end()) Mn(ans, mp[tp ^ v[j]] + siz[j]);
		write(ans == 10000 ? -1 : ans);
	}
	return 0;
}