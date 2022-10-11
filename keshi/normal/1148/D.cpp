//In the name of GOD
//Hello Yellow
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, mp[maxn];

pll a[maxn];

vector<pll> v, g;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i].F >> a[i].S;
		mp[a[i].F] = i + 1;
		if(a[i].F < a[i].S){
			v.pb(a[i]);
		}
		else{
			g.pb(a[i]);
		}
	}
	
	sort(v.begin(), v.end(), greater<pll>());
	sort(g.begin(), g.end());
	
	if(v.size() < g.size()){
		v = g;
	}
	
	cout << v.size() << endl;
	
	for(ll i = 0; i < v.size(); i++){
		cout << mp[v[i].F] << " ";
	}
	
	return 0;
}