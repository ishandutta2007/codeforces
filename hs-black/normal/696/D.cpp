#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 205;
int ch[N][26], f[N], val[N], cnt;
void add(char *s, int x) {
	int l = strlen(s + 1), p = 0;
	for (int i = 1;i <= l; i++) {
		int di = s[i] - 'a';
		if (!ch[p][di]) ch[p][di] = ++cnt;
		p = ch[p][di];
	} val[p] += x;
}

void build(void) {
	queue<int> q;
	for (int i = 0;i < 26; i++) 
		if (ch[0][i]) q.push(ch[0][i]);
	while (q.size()) {
		int x = q.front(); q.pop();
		val[x] += val[f[x]];
		for (int i = 0;i < 26; i++) {
			if (ch[x][i]) f[ch[x][i]] = ch[f[x]][i], q.push(ch[x][i]);
			else ch[x][i] = ch[f[x]][i];
		}
	}
}

inline void Mx(ll &x, ll y) { if (y > x) x = y; }
struct Mat {
	ll f[N][N];
	Mat() { memset(f, -0x3f, sizeof(f));}
	Mat operator * (Mat b) {
		Mat t;
		for (int i = 0;i <= cnt; i++)
			for (int j = 0;j <= cnt; j++)
				for (int k = 0;k <= cnt; k++) 
					Mx(t.f[i][j], f[i][k] + b.f[k][j]);
		return t;
	}
}I, X;

char s[N];
ll a[N], n, l;

void fpw(void) {
	while (l) {
		if (l & 1) I = I * X;
		X = X * X; l >>= 1;
	}	
}

int main() {
	read(n), read(l);
	for (int i = 1;i <= n; i++) read(a[i]);
	for (int i = 1;i <= n; i++)
		scanf ("%s", s + 1), add(s, a[i]);
	build();
	for (int i = 0;i <= cnt; i++) I.f[i][i] = 0;
	for (int i = 0;i <= cnt; i++)
		for (int j = 0;j < 26; j++)
			X.f[i][ch[i][j]] = val[ch[i][j]];
	
	fpw(); ll ans = 0;
	for (int i = 0;i <= cnt; i++) Mx(ans, I.f[0][i]);
	cout << ans << endl;
	return 0;
}