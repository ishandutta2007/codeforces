//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define pcc pair<char, char>
#define shit set<pair<pcc, ll> >
#define F first
#define S second

ll n, cnt;

string s;

map<pcc, ll> in, out;

bool f;

map<pcc, shit> g;

void tur(pcc v){
	pcc u = make_pair(' ', ' ');
	shit::iterator itr = g[v].lower_bound({u, -1});
	while(itr != g[v].end()){
		u = itr -> F;
		g[v].erase(itr);
		tur(u);
		itr = g[v].lower_bound({u, -1});
	}
	if(!f) s += v.F;
	s += v.S;
	f = 1;
	return;
}

int main(){
	char v, u, c;
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> v >> u >> c;
		g[{u, c}].insert({{v, u}, i});
		out[{v, u}]++;
		in[{u, c}]++;
	}
	
	for(map<pcc, ll>::iterator itr = in.begin(); itr != in.end(); itr++){
		if(itr -> S != out[itr -> F]){
			cnt++;
			if(abs(itr -> S - out[itr -> F]) > 1){
				cnt = 10;
			}
			if(out[itr -> F] < itr -> S){
				u = (itr -> F).F;
				c = (itr -> F).S;
			}
		}
	}
	
	if(cnt > 2){
		cout << "NO";
		return 0;
	}
	
	tur({u, c});
	
	if(s.size() != n + 2){
		cout << "NO";
		return 0;
	}
	
	cout << "YES\n" << s;
	
	return 0;
}