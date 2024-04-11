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

vi wagi;
ll ans;
vi syn[2];

int dodaj(){
	FOR(j, 0, 2) syn[j].PB(0);
	return SZ(syn[0]) - 1;
}

void add(int val){
	int akt = 0;
	for(int i = 29; i >= 0; i--){
		int bit = (val >> i) & 1;
		if(!syn[bit][akt]) syn[bit][akt] = dodaj();
		akt = syn[bit][akt];
	}
}

int best(int val){
	int akt = 0, ret = 0;
	for(int i = 29; i >= 0; i--){
		int bit = (val >> i) & 1;
		if(!syn[bit][akt]) ret ^= (1 << i), bit ^= 1;
		akt = syn[bit][akt];
	}
	return ret;
}

int cost(int l, int mid, int r){
	FOR(j, 0, 2) syn[j] = {0};
	int ret = INF;
	FOR(i, l, mid) add(wagi[i]);
	FOR(i, mid, r+1) ret = min(ret, best(wagi[i]));
	return ret;
}

void reku(int l, int r){
	if(wagi[l] >= wagi[r]) return;
	int bit = wagi[l] ^ wagi[r];
	bit = 31 - __builtin_clz(bit);
	int mask = (-1) ^ ((1 << bit) - 1);
	int gosc = wagi[r] & mask;
	int ind = lower_bound(wagi.begin(), wagi.end(), gosc) - wagi.begin();
	reku(l, ind-1), reku(ind, r);
	ans += cost(l, ind, r);
}

void solve(){
	int n;
	cin >> n;
	wagi.resize(n);
	TRAV(x, wagi) cin >> x;
	sort(wagi.begin(), wagi.end());
	reku(0, SZ(wagi)-1);
	cout << ans << '\n';
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