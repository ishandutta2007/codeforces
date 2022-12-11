
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

const int N = 205000;
int n, T, x, y;
int cnt[N], b[N];
vector<int> v[N], vec;
priority_queue<pair<int, int> > q;
int main() {
	read(T);
	for (int p = 1;p <= T; p++) {
		read(n), read(x), read(y);
		while (q.size()) q.pop(); vec.clear();
		for (int i = 1;i <= n + 1; i++) v[i].clear(), cnt[i] = 0;
		for (int i = 1;i <= n; i++) 
			read(b[i]), cnt[b[i]]++;
		int mx = 0;
		for (int j = 1;j <= n + 1; j++)
			if (!cnt[j]) mx = j;
			else q.push(MP(cnt[j], j));
		for (int i = 1;i <= x; i++) {
			int t = q.top().se; q.pop();
			cnt[t]--, v[t].push_back(t);
			if (cnt[t]) q.push(MP(cnt[t], t));
		}
		int res = n - x, mmx = 0;
		for (int i = 1;i <= n + 1; i++) {
			for (int j = 1;j <= cnt[i]; j++)
				vec.push_back(i);
			Mx(mmx, cnt[i]);
		}
		if (mmx * 2 - (n - y) > n - x) { puts("NO"); continue; }
		puts("YES");
		int las = n - y;
		for (int i = 0;i < res; i++) {
			int to = (i + res / 2) % res;
			if (vec[to] == vec[i]) {
				las--; v[vec[i]].push_back(mx);
			}
			else v[vec[i]].push_back(vec[to]);
		}
		for (int i = 1;i <= n; i++) {
			int t = v[b[i]].back(); v[b[i]].pop_back();
			if (las && b[i] != t && t != mx) t = mx, las--; 
			write(t, ' ');
		}
		puts("");
	}
	return 0;
}

/*

1
6 3 3
1 1 2 2 1 1 

*/