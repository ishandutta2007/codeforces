//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

ll t, x1, p1, x2, p2;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> x1 >> p1;
		cin >> x2 >> p2;
		if(p1 - p2 > 10){
			cout << ">\n";
			continue;
		}
		if(p2 - p1 > 10){
			cout << "<\n";
			continue;
		}
		for(ll i = 0; i < p1 - p2; i++){
			x1 *= 10;
		}
		for(ll i = 0; i < p2 - p1; i++){
			x2 *= 10;
		}
		if(x1 > x2){
			cout << ">\n";
			continue;
		}
		if(x1 < x2){
			cout << "<\n";
			continue;
		}
		cout << "=\n";
	}
	
	return 0;
}