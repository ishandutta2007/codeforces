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

const int P = 1e9+7;
const int N = 2005;
ll f[N][N][2], lL, rL;
ll m, d;
char l[N], r[N];
ll work(char *s, int len) {
	int di = s[0] - '0';
	for (int i = 0;i < di; i++) 
		if (i ^ d) f[0][i%m][1]++;
	if (di ^ d) f[0][di%m][0]++;
	for (int i = 1; i < len; i++) {
		di = s[i] - '0';
		for (int j = 0; j <= 9; j++) {
			if (!(i & 1) && j == d) continue;
			if ((i & 1) && j != d) continue;
			for (int k = 0; k < m; k++) {
				int t = (k * 10 + j) % m;
				ll &x = f[i][t][1], &y = f[i][t][0];
				if (j < di) x += (f[i-1][k][0] + f[i-1][k][1]);
				else if (j > di) x += f[i-1][k][1];
				else x += f[i-1][k][1], y += f[i-1][k][0];
				x %= P, y %= P;
			}
		}
	}
	return (f[len-1][0][1] + f[len-1][0][0]) % P;
}

int check(char *s, int len) {
	ll tmp = 0;
	for (int i = 0;i < len; i++) {
		if (i & 1) {
			if (s[i] != d + '0') return 0;
		}
		else if (s[i] == d + '0') return 0;
		tmp = tmp * 10 + s[i] - '0'; 
		tmp %= m;
	}
	return tmp == 0;
}

int main() {
	read(m), read(d);
	scanf ("%s%s", l, r);
	lL = strlen(l), rL = strlen(r);
	ll ans = work(r, rL); 
	memset(f, 0, sizeof(f));
	ans = (ans - work(l, lL) + P) % P;
	ans += check(l, lL);
	cout << ans % P << endl;
	return 0;
}