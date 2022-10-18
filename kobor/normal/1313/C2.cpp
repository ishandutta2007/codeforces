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

vector<ll> get(vi &t, int flag = 0, int who = 0){
	vector<ii> stos;
	vector<ll> ret;
	ll ans = 0;
	FOR(i, 0, SZ(t)){
		ii akt = {t[i], 1};
		while(SZ(stos) && stos.back().X >= akt.X){
			ans -= 1ll * stos.back().X * stos.back().Y;
			akt.Y += stos.back().Y;
			stos.pop_back();
		}
		ans += 1ll * akt.X * akt.Y;
		ret.PB(ans);
		stos.PB(akt);
		if(flag == 1 && who == i){
			FOR(j, 0, SZ(stos)) FOR(k, 0, stos[j].Y) cout << stos[j].X << ' ';
		}
		if(flag == 2 && who == i){
			for(int j=SZ(stos)-1; j>=0; j--) FOR(k, 0, stos[j].Y - (j+1 == SZ(stos))) cout << stos[j].X << ' ';
		}
	}
	reverse(t.begin(), t.end());
	return ret;
}

void solve(){
	int n;
	cin >> n;
	vi t(n);
	TRAV(x, t) cin >> x;
	vector<ll> ans1 = get(t);
	vector<ll> ans2 = get(t);
	reverse(ans2.begin(), ans2.end());
	pair<ll, int> wyn = {0, 0};
	FOR(i, 0, SZ(ans1)) wyn = max(wyn, {ans1[i] + ans2[i] - t[i], i});
	get(t, 1, wyn.Y);
	get(t, 2, n-1-wyn.Y);
	cout << '\n';
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