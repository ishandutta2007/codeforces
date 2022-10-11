//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, t, o;

bool a[maxn];

vector<ll> b[maxn];

char c;

pll p;

int main(){
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 0; i < n; i++){
		cin >> c;
		if(c == 'L') a[i] = 1;
	}
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j + 1 < n; j++){
			if(!a[j] && a[j + 1]) b[i].pb(j);
		}
		for(ll j = 0; j < b[i].size(); j++){
			a[b[i][j]] = 1;
			a[b[i][j] + 1] = 0;
		}
		if(b[i].empty()) break;
		t++;
	}
	
	if(t == k){
		for(ll i = 0; i < t; i++){
			cout << b[i].size() << " ";
			for(ll j = 0; j < b[i].size(); j++){
				cout << b[i][j] + 1 << " ";
			}
			cout << '\n';
		}
		return 0;
	}
	
	p = make_pair(-1ll, -1ll);
	
	for(ll i = 0; i < t; i++){
		for(ll j = 0; j < b[i].size(); j++){
			o++;
			if(o + t - i == k && j + 1 < b[i].size()) p = make_pair(i, j);
		}
	}
	
	if(p.F == -1){
		cout << -1;
		return 0;
	}
	
	for(ll i = 0; i < p.F; i++){
		for(ll j = 0; j < b[i].size(); j++){
			cout << "1 " << b[i][j] + 1 << '\n';
		}
	}
	
	for(ll i = 0; i <= p.S; i++){
		cout << "1 " << b[p.F][i] + 1 << '\n';
	}
	
	cout << b[p.F].size() - p.S - 1 << " ";
	
	for(ll i = p.S + 1; i < b[p.F].size(); i++){
		cout << b[p.F][i] + 1 << " ";
	}
	cout << '\n';
	
	for(ll i = p.F + 1; i < t; i++){
		cout << b[i].size() << " ";
		for(ll j = 0; j < b[i].size(); j++){
			cout << b[i][j] + 1 << " ";
		}
		cout << '\n';
	}
	
	return 0;
}