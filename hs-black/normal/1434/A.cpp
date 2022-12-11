
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

const int N = 100500;
int a[8], b[N*8], ch[N][8], tp[N], cnt, T, n;
struct node {
	int x, num;
	bool operator < (const node &i) const {
		return x > i.x;
	}
}p[N*10];

priority_queue<ll> q1, q2;
int main() {
	for (int i = 1;i <= 6; i++) read(a[i]);
	read(n);
	for (int i = 1, x;i <= n; i++) {
		read(x);
		for (int j = 1;j <= 6; j++)
			p[++cnt] = (node) {x - a[j], i};
	}
	sort(p + 1, p + cnt + 1);
	for (int i = 1;i <= cnt; i++) {
		ch[p[i].num][++tp[p[i].num]] = i;
		if (tp[p[i].num] == 1) q1.push(i);
	}
	int ans = 1e9;
	for (int i = 1;i <= n; i++) tp[i] = 1;
	for (int i = 1;i <= cnt; i++) {
		if (q1.size() - q2.size() < n) break;
		while (q2.size() && q1.top() == q2.top()) q1.pop(), q2.pop();
		Mn(ans, p[i].x - p[q1.top()].x);
//		write(q1.top());
		int t = p[i].num;
		if (tp[t] == 6) break;
		q2.push(i); q1.push(ch[t][++tp[t]]);
	}
	write(ans);
	return 0;
}