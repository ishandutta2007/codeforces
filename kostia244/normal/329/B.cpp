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
//  freopen("input.txt", "r", stdin);
#endif
}
typedef long long ll;
typedef ll _I;
typedef double ld;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, x, y, tx, ty;
int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
pi s, e;
vvc mat;
vvi dist;
queue<pi> q;
int main() {
	doin();
	cin >> n >> m;
	mat.resize(n, vc(m));
	dist.resize(n, vi(m, 10000000));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 'S')
				s = {i, j};
				else if(mat[i][j] == 'E')
				e = {i, j}, dist[i][j]=0;
			}
	q.push(e);
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			tx = x + dx[i];
			ty = y + dy[i];
			if (tx >= 0 && ty >= 0 && tx < n && ty < m && mat[tx][ty] != 'T'
					&& dist[tx][ty] == 10000000) {
				dist[tx][ty] = 1+dist[x][y];
				q.push({tx, ty});
			}
		}
	}
	int base = dist[s.first][s.second], ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if(mat[i][j] > '0' && mat[i][j] <= '9' && dist[i][j]<=base)
				ans+=mat[i][j]-'0';
		}
	cout << ans;
}