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

void solve(){
	int n, m;
	vector<ll> ziomki;
	cin >> n >> m;
	FOR(i, 0, n){
		string s;
		cin >> s;
		ziomki.PB(stoll(s, 0, 2));
	}
	sort(ziomki.begin(), ziomki.end());
	ll l = -1, r = 1ll << m, mid, szuk = ((1ll << m) - n + 1)/2;
	while(l+1 < r){
		mid = (l+r) / 2;
		if(mid + 1 - (upper_bound(ziomki.begin(), ziomki.end(), mid) - ziomki.begin()) >= szuk) r = mid;
		else l = mid;
	}
	for(int i = m-1; i >= 0; i--) cout << ((r >> i) & 1);
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin>>tt;
	FOR(te, 0, tt){
		// cout << "Case #" << te+1 << ": ";
		solve();
	}
	// solve();
	return 0;
}