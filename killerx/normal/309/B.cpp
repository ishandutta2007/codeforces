#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

int n, r, c;
string text;
string s;
int st[1000005];
char tmp[5000005];
int table[1000005][20];

int main() {
	n = read(), r = read(), c = read();
	rep(i, n) {
		scanf("%s", tmp); s = tmp;
		st[i] = text.size();
		text += s + ' ';
	}
	st[n] = text.size();
	rep(i, n) {
		int lb = 0, rb = n - i;
		while (lb < rb) {
			int md = (lb + rb + 1) >> 1;
			if (st[i + md] - st[i] - 1 <= c) lb = md;
			else rb = md - 1;
		}
		table[i][0] = lb;
	}
	for (int j = 1; j < 20; ++ j) {
		rep(i, n) {
			table[i][j] = table[i][j - 1] + table[i + table[i][j - 1]][j - 1];
		}
	}
	int ans = 0, ansn = -1;
	rep(i, n) {
		int cnt = 0;
		int x = i;
		rep(j, 20) if (r & 1 << j) {
			cnt += table[x][j];
			x += table[x][j];
		}
		if (cnt > ans) ans = cnt, ansn = i;
	}
	int x = ansn;
	rep(i, r) {
		if (table[x][0] != 0) printf("%s\n", text.substr(st[x], st[x + table[x][0]] - st[x] - 1).c_str());
		x += table[x][0];
	}
	return 0;
}