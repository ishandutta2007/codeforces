#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF=0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < e; i++)
#define TRAV(x, a) for(auto &x: a)
#define SZ(x) ((int)(x).size())
#define PB push_back
#define PR pair
#define MP make_pair
#define X first
#define Y second

const int N = 1010;
const int mod = 1e9+7;

int n;
int tab[N][N];
int pr[N][N], le[N][N];

vector<vector<ii>> rows, cols, pra, lew;
vector<vi> zrows, zcols, zpra, zlew;

int pov(int base, int exp = mod-2){
	int ret = 1;
	while(exp){
		if(exp&1) ret = 1ll*ret*base%mod;
		base = 1ll*base*base%mod;
		exp>>=1;
	}
	return ret;
}

ii dod(ii a, ii b){
	return {a.X+b.X, a.Y+b.Y};
}

ii ode(ii a, ii b){
	return {a.X-b.X, a.Y-b.Y};
}

ii dud(ii a, int b){
	if(b == 2) a.X++;
	if(b == 3) a.Y++;
	return a;
}

ii udu(ii a, int b){
	if(b == 2) a.X--;
	if(b == 3) a.Y--;
	return a;
}

ii row(int kt, int l, int r){
	if(r+1 >= SZ(rows[kt]) || l < 0) return {-INF, 0};
	if(zrows[kt][r+1] - zrows[kt][l] > 0) return {-INF, 0};
	return ode(rows[kt][r+1], rows[kt][l]);
}

ii col(int kt, int l, int r){
	if(r+1 >= SZ(cols[kt]) || l < 0) return {-INF, 0};
	if(zcols[kt][r+1] - zcols[kt][l] > 0) return {-INF, 0};
	return ode(cols[kt][r+1], cols[kt][l]);
}

ii praq(int kt, int l, int r){
	if(r+1 >= SZ(pra[kt]) || l < 0) return {-INF, 0};
	if(zpra[kt][r+1] - zpra[kt][l] > 0) return {-INF, 0};
	return ode(pra[kt][r+1], pra[kt][l]);
}

ii lewq(int kt, int l, int r){
	if(r+1 >= SZ(lew[kt]) || l < 0) return {-INF, 0};
	if(zlew[kt][r+1] - zlew[kt][l] > 0) return {-INF, 0};
	return ode(lew[kt][r+1], lew[kt][l]);
}

int copr(int i, int j){
	return j-i+(n-1);
}

int cole(int i, int j){
	return i+j;
}

ii cross(int i, int j, int dl, int typ){
	ii ans = {0, 0};
	if(typ == 0){
		ans = dod(row(i, j-dl, j+dl), col(j, i-dl, i+dl));
	}
	else{
		ans = dod(praq(copr(i, j), pr[i][j]-dl, pr[i][j]+dl), lewq(cole(i, j), le[i][j]-dl, le[i][j]+dl));
	}
	return udu(ans, tab[i][j]);
}

ii maks(ii a, ii b){
	ii a2 = a, b2 = b;
	if(a.X < 0 || b.X < 0) return max(a, b);
	int jed = min(a.X, b.X);
	a.X -= jed;
	b.X -= jed;
	int dwa = min(a.Y, b.Y);
	a.Y -= dwa;
	b.Y -= dwa;
	if(a.X > 0 && a.Y > 0) return a2;
	if(b.X > 0 && b.Y > 0) return b2;
	if(a.Y > 0) swap(a, b), swap(a2, b2);
	if(pow(2, a.X) > pow(3, b.Y)) return a2;
	else return b2;
}

void solve(){
	bool zapal = 0;
	ii ans = {-INF, 0};
	cin >> n;
	rows.resize(n, vector<ii>(1));
	cols.resize(n, vector<ii>(1));
	pra.resize(n*2-1, vector<ii>(1));
	lew.resize(n*2-1, vector<ii>(1));
	zrows.resize(n, vi(1, 0));
	zcols.resize(n, vi(1, 0));
	zpra.resize(n*2-1, vi(1, 0));
	zlew.resize(n*2-1, vi(1, 0));
	FOR(i, 0, n) FOR(j, 0, n){
		char c;
		cin >> c;
		tab[i][j] = c-'0';
		zapal |= tab[i][j];
	}
	FOR(i, 0, n) FOR(j, 0, n){
		pr[i][j] = SZ(pra[copr(i, j)])-1;
		le[i][j] = SZ(lew[cole(i, j)])-1;

		rows[i].PB(dud(rows[i].back(), tab[i][j]));
		cols[j].PB(dud(cols[j].back(), tab[i][j]));
		pra[copr(i, j)].PB(dud(pra[copr(i, j)].back(), tab[i][j]));
		lew[cole(i, j)].PB(dud(lew[cole(i, j)].back(), tab[i][j]));

		zrows[i].PB(zrows[i].back()+(tab[i][j]==0));
		zcols[j].PB(zcols[j].back()+(tab[i][j]==0));
		zpra[copr(i, j)].PB(zpra[copr(i, j)].back()+(tab[i][j]==0));
		zlew[cole(i, j)].PB(zlew[cole(i, j)].back()+(tab[i][j]==0));
	}

	FOR(i, 0, n) FOR(j, 0, n) FOR(k, 0, 2){
		int l = 0, r = n+2, mid;
		while(l+1 < r){
			mid = (l+r)/2;
			if(cross(i, j, mid, k).X > -1) l = mid;
			else r = mid;
		}
		ans = maks(ans, cross(i, j, l, k));
	}
	if(!zapal){
		cout << 0 << '\n';
	}
	else if(ans.X < 0){
		cout << -1 << '\n';
	}
	else{
		cout << 1ll*pov(2, ans.X)*pov(3, ans.Y)%mod << '\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 0, tt){
	// 	// cout << "Case #" << te+1 << ": ";
	// 	solve();
	// }
	solve();
	return 0;
}