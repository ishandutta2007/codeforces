#pragma GCC optimize ("Ofast")
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
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
}
template<typename X, typename Y>
istream& operator>>(istream& in, pair<X, Y> &a) {
	in >> a.first >> a.second;
	return in;
}
template<typename T>
void getv(T& i) {
	cin >> i;
}
template<typename T, typename ... Ns>
void getv(vector<T>& v, int n, Ns ... ns) {
	v.resize(n);
	for (auto& i : v)
		getv(i, ns...);
}
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef ll _I;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <vd> vvd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, dp[15][15][1 << 16], sx, sy, ex, ey, l, ans = INT_MAX, dx[] = { 1, 0,
		-1, 0 }, dy[] = { 0, 1, 0, -1 }, MSK, Ln;
ll cnt = 0;
char mat[15][15];
bool valid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}
int startstate(int i = sx, int j = sy) {
	if (mat[i][j] - '0' == l)
		return 0;
	int nx, ny, f = 0;
	for (int p = 0; p < 4; p++) {
		int tx = i + dx[p], ty = j + dy[p];
		if (valid(tx, ty) && int(mat[tx][ty] - mat[i][j]) == 1) {
			nx = tx, ny = ty;
			f = p;
			break;
		}
	}
	return f + 4 * startstate(nx, ny);
}

struct rec {
	int x, y, msk, dist;
	rec(int x, int y, int msk, int dist) {
		this->x = x;
		this->y = y;
		this->msk = msk;
		this->dist = dist;
	}
	bool operator<(const rec& o) const {
		if(dist == o.dist) {
			return abs(x-ex)+abs(y-ey) > abs(o.x-ex)+abs(o.y-ey);
		}
		return dist > o.dist;
	}
};

queue<rec> a;
void dfs(int x, int y, int msk) {
	if(dp[ex][ey][msk] == Ln) {
		cout << dp[ex][ey][msk];
		exit(0);
	}
	cnt++;
	int free = 15;
	int tx = x, ty = y;
	for (int i = 0; i < 2 * (l - 1); i += 2) {
		for (int p = 0; p < 4; p++)
			if (x + dx[p] == tx && y + dy[p] == ty) {
				free ^= 1 << p;
			}
		tx = tx + dx[(msk >> i) & 3];
		ty = ty + dy[(msk >> i) & 3];
	}
	for (int p = 0; p < 4; p++) {
		int tx = x + dx[p], ty = y + dy[p], nmsk = msk;
		nmsk = (nmsk<<2)&MSK;
		nmsk+=p^2;
		if ((free&(1<<p)) && valid(tx, ty) && mat[tx][ty] != '#' && dp[tx][ty][nmsk]==1000) {
			dp[tx][ty][nmsk] = dp[x][y][msk]+1;
			a.push(rec(tx, ty, nmsk, dp[x][y][msk]+1));
		}
	}
}

int main() {
	doin();
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == '@')
				ex = i, ey = j;
			if (mat[i][j] == '1')
				sx = i, sy = j;
			if (mat[i][j] >= '1' && mat[i][j] <= '9')
				l = max(mat[i][j] - '0', l);
		}
	MSK = 1 << (2 * (l - 1));
	MSK--;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int msk = 0; msk <= MSK; msk++)
				dp[i][j][msk] = 1000;
	int ss = startstate();
	Ln = abs(sx-ex)+abs(sy+ey);
	a.push(rec(sx, sy, ss, 0));
	while(!a.empty()) {
		rec r = a.front();
		a.pop();
		if(dp[r.x][r.y][r.msk] < r.dist)
			continue;
		dp[r.x][r.y][r.msk] = r.dist;
		dfs(r.x, r.y, r.msk);
		if(r.x == ex && r.y == ey)
			return cout << r.dist, 0;
	}
	for (int i = 0; i <= MSK; i++)
		for(int j = 0; j < 26; j++)
		ans = min(ans, dp[ex][ey][i]);
	if (ans == 1000)
		cout << -1;
	else
		cout << ans;
}