//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 1024;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

int n, m;
ll fen[4][maxn][maxn];

inline void upd(int f, int i, int j, ll x){
	for(i += 5; i < maxn; i += i & -i){
		for(int jj = j + 5; jj < maxn; jj += jj & -jj){
			fen[f][i][jj] ^= x;
		}
	}
	return;
}
inline ll get(int f, int i, int j){
	int x = 0;
	for(i += 5; i > 0; i -= i & -i){
		for(int jj = j + 5; jj > 0; jj -= jj & -jj){
			x ^= fen[f][i][jj];
		}
	}
	return x;
}
inline void upd(int x, int y, int v){
	int f = 0;
	if(x & 1) f++;
	if(y & 1) f += 2;
	upd(f, x, y, v);
}
inline ll get(int x, int y){
	int f = 0;
	if(x & 1) f++;
	if(y & 1) f += 2;
	return get(f, x, y);
}

int main(){
	fast_io;
	
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int t, x0, x1, y0, y1;
		cin >> t >> x0 >> y0 >> x1 >> y1;
		if(t == 2){
			ll v;
			cin >> v;
			y1++;
			x1++;
			upd(x0, y0, v);
			upd(x0, y1, v);
			upd(x1, y0, v);
			upd(x1, y1, v);
		}
		else{
			x0--;
			y0--;
			cout << (get(x0, y0) ^ get(x0, y1) ^ get(x1, y0) ^ get(x1, y1)) << "\n";
		}
	}
	
	return 0;
}