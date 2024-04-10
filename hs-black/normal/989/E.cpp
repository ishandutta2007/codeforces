/*
    ___                         ______      __                  __
   /   |____  __  ___________ _/ ____/___ _/ /___  ____  ______/ /____
  / /| /_  / / / / / ___/ __ `/ /   / __ `/ __/ / / / / / / __  / ___/
 / ___ |/ /_/ /_/ (__  ) /_/ / /___/ /_/ / /_/ /_/ / /_/ / /_/ (__  )
/_/  |_/___/\__,_/____/\__,_/\____/\__,_/\__/\__, /\__, /\__,_/____/
                                            /____//____/

 
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

const int N = 201;
struct Mat {
	double f[N][N];
	int n, m;
	Mat (int nn = 0, int mm = 0) {
		n = nn, m = mm;
		for (int i = 1;i <= nn; ++i)
			memset(f[i], 0, sizeof(f[i]));
	}
	double * operator [](int x) { return f[x]; }
	Mat operator * (Mat g) {
		Mat t(n, g.m);
		for (int k = 1;k <= m; ++k)
			for (int i = 1;i <= n; ++i)
				for (int j = 1;j <= g.m; ++j)
					t[i][j] += f[i][k] * g[k][j];
		return t;
	}
}X, I, R[20];
void prework(void) {
	R[0] = X;
	for (int i = 1;i <= 14; ++i)
		R[i] = R[i-1] * R[i-1];
}

int vis[N][N], x[N], y[N], cnt, n, q;
vector<int> vec[N * N], bl[N];
int main() {
	read(n); X.n = X.m = I.n = I.m = n;
	for (int i = 1;i <= n; ++i) read(x[i]), read(y[i]), I[i][i] = 1;
	for (int i = 1;i <= n; ++i) {
		for (int j = 1;j <= n; ++j) if (i != j && !vis[i][j]) {
			++cnt;
			for (int k = 1;k <= n; ++k) 
				if ((x[k] - x[i]) * (y[j] - y[i]) - (x[j] - x[i]) * (y[k] - y[i]) == 0)
					vec[cnt].push_back(k);
			for (int a = 0; a < vec[cnt].size(); ++a) {
				int x = vec[cnt][a];
				bl[x].push_back(cnt);
				for (int b = 0; b < vec[cnt].size(); ++b) {
					int y = vec[cnt][b];
					vis[x][y] = vis[y][x] = cnt;
				}
			}
		}
	}
	for (int i = 1;i <= n; ++i) {
		double bt = 1.0 / bl[i].size();
		for (int j = 0;j < bl[i].size(); ++j) {
			int id = bl[i][j];
			double pt = bt / vec[id].size();
			for (int k = 0;k < vec[id].size(); ++k) 
				X[vec[id][k]][i] += pt;
		}
	}
//	for (int i = 1;i <= cnt; ++i) {
//		printf ("the %dth LINE:: \n", i);
//		for (int t: vec[i]) write(t, ' ');
//		puts("");
//	}
	for (prework(), read(q); q; q--) {
		int m, t;
		read(t), read(m);
		Mat T(1, n);
		T[1][t] = 1, --m;
		for (int i = 0;i <= 14; ++i) 
			if (m >> i & 1) T = T * R[i];
		double ans = 0;
		for (int i = 1;i <= cnt; ++i) {
			double res = 0;
			for (int j = 0;j < vec[i].size(); ++j)
				res += T[1][vec[i][j]];
			Mx(ans, res / vec[i].size());
		}
		printf ("%.10lf\n", ans);
	}
	return 0;
}

/*

5
0 0
1 3
2 2
3 1
4 4
5
3 2
3 3
3 4
3 5
3 6

*/