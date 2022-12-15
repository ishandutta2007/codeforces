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

const int N = 300500;
int T, n, a[N];

priority_queue<pair<int, int> > q;
int tmp[N], cnt[N], t;
bool check(int mid) {
	memset(cnt, 0, n * 4 + 50);
	memset(tmp, 0, n * 4 + 50);
	while (q.size()) q.pop();
	for (int i = 1;i <= n; i++) cnt[a[i]]++;
	for (int i = 1;i <= n; i++) 
		if (cnt[i]) q.push(MP(cnt[i], i));
	for (int i = 1;i <= n; i++) {
		if (tmp[i]) q.push(MP(cnt[tmp[i]], tmp[i]));
		if (!q.size()) return 0;
		int x = q.top().se; q.pop();
		cnt[x]--;
		if (cnt[x]) {
			if (i + mid + 1> n) return 0;
			tmp[i + mid + 1] = x;
		}
	}
	return 1;
}

int main() {
	for (read(T); T; T--) {
		read(n);
		for (int i = 1;i <= n; i++) read(a[i]);
		int l = 1, r = n - 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) l = mid + 1;
			else r = mid - 1;
		}
		write(r);
	}
	return 0;
}

/*

4
7
1 7 1 6 4 4 6


8
1 1 4 6 4 6 4 7


3
3 3 3

6
2 5 2 3 1 4

*/