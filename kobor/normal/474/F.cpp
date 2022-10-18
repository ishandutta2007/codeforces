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

const int T = 1<<18;

ii mink[T*2+5], gcdk[T*2];

ii mergemin(ii &a, ii &b){
	ii ret = {min(a.X, b.X), 0};
	if(ret.X == a.X) ret.Y += a.Y;
	if(ret.X == b.X) ret.Y += b.Y;
	return ret;
}

ii mergegcd(ii &a, ii &b){
	ii ret = {gcd(a.X, b.X), 0};
	if(ret.X == a.X) ret.Y += a.Y;
	if(ret.X == b.X) ret.Y += b.Y;
	return ret;
}

int query(int l, int r){
	ii aktmin = {INF, 0};
	ii aktgcd = {0, 0};
	l += T, r += T;
	while(l <= r){
		if(l&1){
			aktmin = mergemin(aktmin, mink[l]);
			aktgcd = mergegcd(aktgcd, gcdk[l++]);
		}
		if((r&1)^1){
			aktmin = mergemin(aktmin, mink[r]);
			aktgcd = mergegcd(aktgcd, gcdk[r--]);
		}
		l >>= 1, r>>=1;
	}
	return (aktmin.X == aktgcd.X ? aktmin.Y : 0);
}

void solve(){
	int n, a;
	cin >> n;
	FOR(i, 0, n){
		cin >> a;
		mink[i+T].X = gcdk[i+T].X = a;
		mink[i+T].Y = gcdk[i+T].Y = 1;
	}
	FOR(i, n, T) mink[i+T].X = INF;
	for(int i = T-1; i > 0; i--){
		mink[i] = mergemin(mink[i*2], mink[i*2+1]);
		gcdk[i] = mergegcd(gcdk[i*2], gcdk[i*2+1]);
	}
	cin >> n;
	FOR(i, 0, n){
		int l, r;
		cin >> l >> r;
		cout << r - l + 1 - query(l-1, r-1) << '\n';
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