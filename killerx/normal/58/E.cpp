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

char tochar(int x) {return x + '0';}
string ans(45, '0');
void dfs(ll a, ll b, ll c, string x, string y, string z, int add) {
	if ((int) (x.size() + y.size() + z.size()) - 1 >= (int) ans.size()) return;
	if (!a && !b && !c) {
		if (add) return;
		while (x[0] == '0') x = x.substr(1);
		while (y[0] == '0') y = y.substr(1);
		while (z[0] == '0') z = z.substr(1);
		if (x.size() + y.size() + z.size() + 2 >= ans.size()) return;
		ans = x + "+" + y + "=" + z;
	}
	if ((a % 10 + b % 10 + add) % 10 == c % 10) {
		dfs(a / 10, b / 10, c / 10, tochar(a % 10) + x, tochar(b % 10) + y, tochar(c % 10) + z, (a % 10 + b % 10 + add) / 10);
	} else {
		dfs(a, b / 10, c / 10, tochar((c % 10 - b % 10 - add + 10) % 10) + x, tochar(b % 10) + y, tochar(c % 10) + z, c % 10 - b % 10 - add < 0);
		dfs(a / 10, b, c / 10, tochar(a % 10) + x, tochar((c % 10 - a % 10 - add + 10) % 10) + y, tochar(c % 10) + z, c % 10 - a % 10 - add < 0);
		dfs(a / 10, b / 10, c, tochar(a % 10) + x, tochar(b % 10) + y, tochar((a % 10 + b % 10 + add) % 10) + z, (a % 10 + b % 10 + add) / 10);
	}
}

int main() {
	ll a = read(), b = read(), c = read();
	dfs(a, b, c, "", "", "", 0);
	printf("%s\n", ans.c_str());
	return 0;
}