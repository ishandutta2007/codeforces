
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

#include <set>
const int N = 200500;
struct node {
	int l, r, t;
	bool operator < (const node &i) const {
		return r == i.r ? l < i.l : r < i.r;
	}
}p[N];

int n;
multiset<int> mp[2];
int main() {
	read(n);
	for (int i = 1;i <= n; i++)
		read(p[i].l), read(p[i].r), read(p[i].t), p[i].t--;
	sort(p + 1, p + n + 1);
	int ans = n;
	for (int i = 1;i <= n; i++) {
		auto it = mp[!p[i].t].lower_bound(p[i].l);
		if (it == mp[!p[i].t].end()) 
			mp[p[i].t].insert(p[i].r);
		else ans--, mp[!p[i].t].erase(it);
	}
	write(ans);
	return 0;
}