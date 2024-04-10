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

const int N = 50005;
struct node {
	int x, y, num;
}q[N];

#define Pa pair<int, int> 
int n, p, s; int ans;
priority_queue<Pa> q1, q2, q3, q4;
int vis[N];

Pa get(priority_queue<Pa> &q) {
	do {
		Pa t = q.top();
		if (!vis[t.se]) return t;
		q.pop();
	}while (1);
}

const int inf = 1e9;
int main() {
	read(n), read(p), read(s);
	for (int i = 1;i <= n; i++) read(q[i].x), q1.push(MP(q[i].x, i));
	for (int i = 1;i <= n; i++) read(q[i].y), q2.push(MP(q[i].y, i));
	while (p || s) {
		Pa A = get(q1), B = get(q2);
		if (!p) {
			if (q3.empty()) A.fi = -inf;
			else A.fi += q3.top().fi;
		}
		if (!s) {
			if (q4.empty()) B.fi = -inf;
			else B.fi += q4.top().fi;
		}
		if (A.fi > B.fi) {
			ans += A.fi; 
			if (p) p--;
			else {
				s--;
				Pa t = q3.top(); q3.pop();
				q4.push(MP(-t.fi, t.se));
			}
			q3.push(MP(q[A.se].y - q[A.se].x, A.se));
			vis[A.se] = 1;
		}
		else {
			ans += B.fi;
			if (s) s--;
			else {
				p--;
				Pa t = q4.top(); q4.pop();
				q3.push(MP(-t.fi, t.se));
			}
			q4.push(MP(q[B.se].x - q[B.se].y, B.se));
			vis[B.se] = 1;
		}
	}
	write(ans);
	while (q3.size()) write(q3.top().se, ' '), q3.pop();
	puts("");
	while (q4.size()) write(q4.top().se, ' '), q4.pop();
	return 0;
}