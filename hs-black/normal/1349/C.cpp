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

const int N = 2005;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char s[N];
int a[N][N], t[N][N];
int ki[N][N], m, n, Q;
bool in(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

queue<pair<int, int> > q;
int main() {
	read(n), read(m), read(Q);
	for (int i = 1;i <= n; i++) {
		scanf ("%s", s + 1);
		for (int j = 1;j <= m; j++) 
			a[i][j] = s[j]-'0';
	}
	for (int i = 1;i <= n; i++)
		for (int j = 1;j <= m; j++) {
			for (int k = 0;k < 4; k++) {
				int x = i + dx[k], y = j + dy[k];
				if (in(x, y) && a[x][y] == a[i][j]) {
					t[i][j] = 1; q.push(MP(i, j)); break;
				}
			}
		}
	while (q.size()) {
		int x = q.front().fi, y = q.front().se; q.pop();
		for (int i = 0;i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (!in(xx, yy) || t[xx][yy]) continue;
			t[xx][yy] = t[x][y] + 1; q.push(MP(xx, yy));
		}
	}
	
	for (int i = 1;i <= Q; i++) {
		ll x, y, p; read(x), read(y), read(p);
		if (!t[x][y] || p < t[x][y]) write(a[x][y]);
		else {
			if ((p + t[x][y]) & 1) write(a[x][y]);
			else write(!a[x][y]);
		}
	}
	return 0;
}