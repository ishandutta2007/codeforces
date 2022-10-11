//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, b, ans;

vector<ll> a;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> b;
		a.pb(b);
	}
	
	sort(a.begin(), a.end());
	
	while(!a.empty()){
		b = a[0];
		ans++;
		for(ll i = 0; i < a.size(); i++){
			if(a[i] % b == 0){
				a.erase(a.begin() + i);
				i--;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}