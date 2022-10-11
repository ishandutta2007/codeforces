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

ll n, t;

pair<pll, ll> a[maxn];

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		for(ll i = 1; i < 2 * n; i++){
			cin >> a[i].F.F >> a[i].F.S;
			a[i].S = i;
		}
		sort(a + 1, a + 2 * n, greater<pair<pll, ll> >());
		cout << "YES\n" << a[1].S << " ";
		for(ll i = 2; i + 1 < 2 * n; i += 2){
			if(a[i].F.S > a[i + 1].F.S) cout << a[i].S << " ";
			else cout << a[i + 1].S << " ";
		}
		cout << '\n';
	}
	
	return 0;
}