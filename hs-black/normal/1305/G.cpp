#pragma GCC optimize(2)
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
inline void write(F x)
{
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar('\n');
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int lim = 1 << 18, N = lim + 5;
ll sum, n;
int f[N], cnt[N];
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

int main() {
	read(n);
	for (int i = 1, x;i <= n; i++) 
		read(x), cnt[x]++, sum -= x;
	for (int i = 1;i <= lim; i++) f[i] = i;
	cnt[0]++;
	for (int i = lim - 1;i >= 0; i--) {
		for (int j = i; j; j = (j - 1) & i) {
			if (!cnt[j] || !cnt[i ^ j]) continue;
			int x = find(j), y = find(i ^ j);
			if (x == y) continue;
			f[y] = x, sum += (ll)(cnt[j] + cnt[i ^ j] - 1) * i;
			cnt[j] = cnt[i ^ j] = 1;
		}
	}
	write(sum);
	return 0;
}