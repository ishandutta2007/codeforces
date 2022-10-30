#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long ll;
typedef long double ld;
#define DIM 1007
#define DIM2 DIM*150
#define MODULO 1000000007
#define MAXN 1000000
#define MS 302
#define BigNumSize 250
#define AddLimit 151
const long INF = 10E16;
const ll mask = po(9) - 1;
const ll base = 100000000000;
const ld eps = 0.0000001;
struct pp {
	ll fi, sc;
	bool const operator < (const pp& b) {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool const operator > (const pp& b) {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool const operator == (const pp& b) {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
bool const operator<(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc < b.sc;
	return a.fi < b.fi;
}
ll n, m, p,S[15],B,dist[DIM][DIM],V[DIM][DIM],M[15],R[15];
char A[DIM][DIM];
queue<pp> border[15];
bool Ch(ll x, ll y) {
	if (x > n || x<1 || y>m || y < 1 || A[x][y] != '.' || V[x][y]==1)return 0;
	return 1;
}
bool can(ll x, ll y) {
	return Ch(x+1,y) || Ch(x,y+1) || Ch(x-1,y) || Ch(x,y-1);
}
queue<pp> Q;
void bfs(ll player) {
	while (!Q.empty()) {
		ll x = Q.front().fi,y = Q.front().sc;
		Q.pop();
		if (dist[x][y] == S[player] * M[player]) {
			border[player].push({ x,y });
			continue;
		}
		if (Ch(x + 1, y)) {
			dist[x + 1][y] = dist[x][y]+1;
			V[x+1][y] = 1;
			Q.push({ x + 1,y });
			A[x + 1][y] = player + '0';
		}
		if (Ch(x-1,y)){
			dist[x - 1][y] = dist[x][y]+1;
			V[x - 1][y] = 1;
			Q.push({ x - 1,y });
			A[x - 1][y] = player + '0';
		}
		if (Ch(x, y - 1)) {
			dist[x][y - 1] = dist[x][y] + 1;
			V[x][y - 1] = 1;
			Q.push({ x,y - 1 });
			A[x][y - 1] = player + '0';
		}
		if (Ch(x, y + 1)) {
			dist[x][y + 1] = dist[x][y] + 1;
			V[x][y + 1] = 1;
			Q.push({ x,y + 1 });
			A[x][y + 1] = player + '0';
		}
	}
}
void play(ll x) {
	M[x]++;
	B -= border[x].size();
	while (!border[x].empty()) {
		pp to = border[x].front();
		if (dist[to.fi][to.sc] > S[x]*M[x])break;
		Q.push(to);
		border[x].pop();
	}
	bfs(x);
	B += border[x].size();
	
}
int main() {
	schnell;
	cin >> n >> m >> p;
	forn(i, p)cin >> S[i];
	forn(i, n) {
		forn(j, m) {
			cin >> A[i][j];
		}
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			if (A[i][j] - '0' >= 0 && A[i][j] - '0' <= p && can(i, j)) {
				border[A[i][j] - '0'].push({ i,j }); V[i][j] = 1;
			}
		}
	}
	for (ll i = 1; i <= p; i++)
		B += border[i].size();
	ll turn = 1;
	while (B > 0) {
		play(turn);
		turn++;
		if (turn > p)turn -= p;
	}
	for(ll i = 1; i <= n;i++) {
		for (ll j = 1; j <= m;j++) {
			if (A[i][j] - '0' >= 0 && A[i][j] - '0' <= p)R[A[i][j] - '0']++;
		}
	}
	forn(i, p)cout << R[i] << ' ';
	cout << endl;
	return 0;
}