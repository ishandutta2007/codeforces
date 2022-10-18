#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF=0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define PR pair
#define MP make_pair
#define X first
#define Y second

const int N = 1e5+5;
const int SQR = 400;

int n, m, k;
int t[N], pref[N];
ll ans[N], gans;
int cnt[11*N];

bool cmp(pair<ii, int> a, pair<ii, int> b){
	if(a.X.X/SQR == b.X.X/SQR) return a.X.Y < b.X.Y;
	return a.X.X > b.X.X;
}

void dod(int ind){
	gans += cnt[pref[ind]^k];
	cnt[pref[ind]]++;
}

void usu(int ind){
	cnt[pref[ind]]--;
	gans -= cnt[pref[ind]^k];
}

void solve(){
	cin >> n >> m >> k;
	FOR(i, 1, n+1) cin >> t[i];
	FOR(i, 1, n+1) pref[i] = pref[i-1] ^ t[i];
	vector<pair<ii, int>> que;
	FOR(i, 0, m){
		int l, r;
		cin >> l >> r;
		que.PB({{l-1, r}, i});
	}
	sort(que.begin(), que.end(), cmp);
	int l = 0, r = -1;
	TRAV(x, que){
		ii akt = x.X;
		while(r < akt.Y) dod(++r);
		while(l > akt.X) dod(--l);
		while(l < akt.X) usu(l++);
		while(r > akt.Y) usu(r--);
		ans[x.Y] = gans;
	}
	FOR(i, 0, m) cout << ans[i] << '\n';
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