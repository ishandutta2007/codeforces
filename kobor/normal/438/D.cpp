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

ll sum[T*2+5];
ii maks[T*2+5];

pair<ll, ii> query(int l, int r){
	pair<ll, ii> ret;
	l += T, r += T;
	while(l <= r){
		if(l&1){
			ret.X += sum[l];
			ret.Y = max(ret.Y, maks[l++]);
		}
		if(!(r&1)){
			ret.X += sum[r];
			ret.Y = max(ret.Y, maks[r--]);
		}
		l >>= 1, r >>= 1;
	}
	return ret;
}

void add(int v, int val){
	v += T;
	sum[v] = val, maks[v] = {val, v-T};
	v >>= 1;
	while(v){
		sum[v] = sum[v*2]+sum[v*2+1];
		maks[v] = max(maks[v*2], maks[v*2+1]);
		v >>= 1;
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
	FOR(i, 0, n){
		int a;
		cin >> a;
		add(i, a);
	}
	FOR(i, 0, m){
		int typ, a, b, c;
		cin >> typ >> a >> b;
		if(typ == 1) cout << query(a-1, b-1).X << '\n';
		if(typ == 2){
			cin >> c;
			ii xd = query(a-1, b-1).Y;
			while(xd.X >= c){
				add(xd.Y, xd.X % c);
				xd = query(a-1, b-1).Y;
			}
		}
		if(typ == 3) add(a-1, b);
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