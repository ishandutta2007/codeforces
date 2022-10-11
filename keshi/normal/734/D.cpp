//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
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

int n;
map<int, vector<pii> > vx, vy, vd1, vd2;
vector<pii> vec;

int main(){
	fast_io;
	
	cin >> n;
	{
		int x, y;
		cin >> x >> y;
		vx[x].pb(Mp(y, 0));
		vy[y].pb(Mp(x, 0));
		vd1[x + y].pb(Mp(x - y, 0));
		vd2[x - y].pb(Mp(x + y, 0));
	}
	for(int i = 0; i < n; i++){
		char c;
		int x, y, f;
		cin >> c;
		if(c == 'B') f = 1;
		if(c == 'R') f = 2;
		if(c == 'Q') f = 3;
		cin >> x >> y;
		vx[x].pb(Mp(y, f));
		vy[y].pb(Mp(x, f));
		vd1[x + y].pb(Mp(x - y, f));
		vd2[x - y].pb(Mp(x + y, f));
	}
	for(auto i : vx){
		vec = i.S;
		sort(all(vec));
		for(int i = 0; i < Sz(vec); i++){
			if(vec[i].S) continue;
			if(i > 0 && vec[i - 1].S != 1){
				cout << "YES\n";
				return 0;
			}
			if(i + 1 < Sz(vec) && vec[i + 1].S != 1){
				cout << "YES\n";
				return 0;
			}
		}
	}
	for(auto i : vy){
		vec = i.S;
		sort(all(vec));
		for(int i = 0; i < Sz(vec); i++){
			if(vec[i].S) continue;
			if(i > 0 && vec[i - 1].S != 1){
				cout << "YES\n";
				return 0;
			}
			if(i + 1 < Sz(vec) && vec[i + 1].S != 1){
				cout << "YES\n";
				return 0;
			}
		}
	}
	for(auto i : vd1){
		vec = i.S;
		sort(all(vec));
		for(int i = 0; i < Sz(vec); i++){
			if(vec[i].S) continue;
			if(i > 0 && vec[i - 1].S != 2){
				cout << "YES\n";
				return 0;
			}
			if(i + 1 < Sz(vec) && vec[i + 1].S != 2){
				cout << "YES\n";
				return 0;
			}
		}
	}
	for(auto i : vd2){
		vec = i.S;
		sort(all(vec));
		for(int i = 0; i < Sz(vec); i++){
			if(vec[i].S) continue;
			if(i > 0 && vec[i - 1].S != 2){
				cout << "YES\n";
				return 0;
			}
			if(i + 1 < Sz(vec) && vec[i + 1].S != 2){
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	
	return 0;
}