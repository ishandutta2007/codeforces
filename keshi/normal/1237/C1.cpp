//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

#define x F.F
#define y F.S
#define z S

ll n;

bool vis[maxn];

pair<pll, ll> p[maxn];

vector<pair<ll, pll> > v;

ll dis(ll i, ll j){
	return (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y) + (p[i].z - p[j].z) * (p[i].z - p[j].z);
}

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> p[i].x >> p[i].y >> p[i].z;
		for(ll j = 0; j < i; j++){
			v.pb({dis(i, j), {i, j}});
		}
	}
	
	sort(v.begin(), v.end());
	
	for(ll i = 0; i < v.size(); i++){
		if(!vis[v[i].S.F] && !vis[v[i].S.S]){
			cout << v[i].S.F + 1 << " " << v[i].S.S + 1 << endl;
			vis[v[i].S.F] = 1;
			vis[v[i].S.S] = 1;
		}
	}
	
	return 0;
}