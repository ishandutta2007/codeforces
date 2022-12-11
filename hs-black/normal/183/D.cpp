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

priority_queue<pair<double, int> > q;

const int N = 3005;
double f[2*N][N], p[N][N], sum[N];
int st[N], m, n, cnt;
int main() {
	read(n), read(m);
	for (int i = 1;i <= n; i++)
		for (int j = 1, P;j <= m; j++) 
			read(P), p[i][j] = (double)P / 1000.0;
	for (int i = 1;i <= m; i++) {
		int a = st[i] = ++cnt; f[a][0] = 1;
		for (int j = 1;j <= n; j++)
			f[a][j] = f[a][j-1] * (1 - p[j][i]);
		sum[i] = 1 - f[a][n], q.push(MP(sum[i], i));
	}
	double ans = 0;
	for (int i = 1;i <= n; i++) {
		int t = q.top().se; q.pop(), ans += sum[t];
		int pr = st[t], nw = st[t] = ++cnt;
		double *fp = f[pr], *fw = f[nw];
		for (int j = 1;j <= n; j++)
			fw[j] = fw[j-1] * (1 - p[j][t]) + fp[j-1] * p[j][t];
		sum[t] -= fw[n], q.push(MP(sum[t], t));
	}
	printf ("%.9lf\n", ans);
	return 0;
}