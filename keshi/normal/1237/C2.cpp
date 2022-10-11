//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e4 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

#define x F.F
#define y F.S
#define z S.F
#define ind S.S

ll n, t, c, d;

bool vis[maxn];

pair<pll, pll> p[maxn];

vector<ll> v;

ll dis(ll i, ll j){
	return (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y) + (p[i].z - p[j].z) * (p[i].z - p[j].z);
}

void solve(){
	for(ll i = d; i < c; i++){
		if(i + 1 < c && p[i].y == p[i + 1].y){
			cout << p[i].ind << " " << p[i + 1].ind << endl;
			i++;
		}
		else{
			v.pb(p[i].ind);
		}
	}
	while(v.size() > 1){
		cout << v.back() << " ";
		v.pop_back();
		cout << v.back() << endl;
		v.pop_back();
	}
	return;
}

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> p[i].x >> p[i].y >> p[i].z;
		p[i].ind = i + 1;
	}
	
	sort(p, p + n);

	while(c < n){
		d = c;
		while(c + 1 < n && p[c].x == p[c + 1].x) c++;
		c++;
		solve();
	}
	
	return 0;
}