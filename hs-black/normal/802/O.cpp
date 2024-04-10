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

#define Pa pair<ll, int>

Pa operator + (Pa A, Pa B) { return MP(A.fi + B.fi, A.se + B.se); }
Pa operator + (Pa A, ll b) { return MP(A.fi + b, A.se); }

const int N = 1000500;
ll a[N], b[N], n, k;
Pa check(ll val) {
	priority_queue<Pa> q;
	Pa ans(0, 0);
	for (int i = 1;i <= n; i++) {
		q.push(MP(-(a[i] + val), 1));
		Pa t = q.top(); t.fi = -t.fi;
		if (t.fi + b[i] <= 0) {
			ans = ans + t + b[i], q.pop();
			q.push(MP(b[i], 0));
		}
	}
	return ans;
}

int main() {
//	freopen ("hs.in","r",stdin);
	read(n), read(k);
	for (int i = 1;i <= n; i++) read(a[i]);
	for (int i = 1;i <= n; i++) read(b[i]);
	ll l = -2e9, r = 2e9;
	while (l <= r) {
		int mid = (l + r) >> 1;
		Pa tmp = check(mid);
		if (tmp.se >= k) l = mid + 1;
		else r = mid - 1;
	}
	Pa tmp = check(r);
//	write(r);
	write(tmp.fi - (ll)k * r);
	return 0;
}