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

ll ans, n;
priority_queue<ll> q;
int main() {
	read(n);
	for (int i = 1, p;i <= n; i++) {
		read(p);
		if (!q.size()) q.push(-p);
		else {
			ll t = -q.top();
			if (t >= p) { q.push(-p); continue; }
			ans += p - t; q.pop();
			q.push(-p), q.push(-p);
		}
	}
	write(ans);
	return 0;
}