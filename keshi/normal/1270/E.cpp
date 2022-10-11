//In the name of GOD
//Good Bye 2019
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
#define x first
#define y second

ll n;

pll p[maxn];

vector<ll> v;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> p[i].x >> p[i].y;
	}
	
	while(true){
		v.clear();
		for(ll i = 0; i < n; i++){
			if((p[i].x + p[i].y) % 2) v.pb(i);
		}
		if(1 <= v.size() && v.size() < n){
			cout << v.size() << '\n';
			for(ll j = 0; j < v.size(); j++){
				cout << v[j] + 1 << " ";
			}
			return 0;
		}
		else if(v.size() == n){
			for(ll i = 0; i < n; i++){
				p[i].x--;
			}
		}
		else{
			v.clear();
			for(ll i = 0; i < n; i++){
				if(p[i].x % 2) v.pb(i);
			}
			if(v.size() == 0){
				for(ll i = 0; i < n; i++){
					p[i].x /= 2;
					p[i].y /= 2;
				}
			}
			else if(v.size() == n){
				for(ll i = 0; i < n; i++){
					p[i].x--;
					p[i].y--;
				}
			}
			else{
				cout << v.size() << '\n';
				for(ll j = 0; j < v.size(); j++){
					cout << v[j] + 1 << " ";
				}
				return 0;
			}
		}
	}
	
	
	return 0;
}