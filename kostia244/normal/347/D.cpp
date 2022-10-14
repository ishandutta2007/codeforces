#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCAL
//	freopen("in", "r", stdin);
#endif
}

template<typename T>
void getv(T& a, int n) {
	a.resize(n);
	for (auto& i : a)
		cin >> i;
}

typedef long long ll;
typedef ll _I;
typedef double ld;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string a, b, v, t;
int dp[101][101][101], cnt  = 0, pk[101][101][101], tp[101][101][101], AB[101][101];
int p[101];

bool ff = true;
int f(int i, int j, int k) {
	if (i == a.size() || j == b.size())
		return 0;
	if(dp[i][j][k] != -1)
		return dp[i][j][k];
	dp[i][j][k] = 0;
	int ta = f(i + 1, j, k), tb = f(i, j + 1, k);
	if (ta > tb)
		dp[i][j][k] = ta, pk[i][j][k] = k, tp[i][j][k] = 1;
	else
		dp[i][j][k] = tb, pk[i][j][k] = k, tp[i][j][k] = 2;
	int newk = k;
	if (AB[i][k] == -1) {
		while (newk != -1 && v[newk] != a[i])
			newk = p[newk];
		newk++;
		AB[i][k] = newk;
	} else
		newk = AB[i][k];
	if (a[i] == b[j] && newk < v.size()) {
		int tc = f(i + 1, j + 1, newk);
		if ((1 + tc) > dp[i][j][k])
			dp[i][j][k] = 1 + tc, pk[i][j][k] = newk, tp[i][j][k] = 3;
	}
	return dp[i][j][k];
}

void bt(int i = 0, int j = 0, int k = 0) {
	if (i == a.size() || j == b.size())
		return;
	if (tp[i][j][k] == 3) {
		cout << a[i];
		ff = false;
		bt(i + 1, j + 1, pk[i][j][k]);
	} else if (tp[i][j][k] == 2) {
		bt(i, j + 1, pk[i][j][k]);
	} else {
		bt(i + 1, j, pk[i][j][k]);
	}
}

int main() {
	doin();
	for (int i = 0; i <= 100; i++)
		for (int i1 = 0; i1 <= 100; AB[i][i1] = -1, i1++)
			for (int i2 = 0; i2 <= 100; i2++)
				dp[i][i1][i2] = -1;
	cin >> a >> b >> v;
	int i = 0, j = -1;
	p[0] = -1;
	while (i < v.size()) {
		while (j != -1 && v[i] != v[j])
			j = p[j];
		j++, i++;
		p[i] = j;
	}
	f(0, 0, 0);
	bt();
	if (ff)
		cout << 0;
}