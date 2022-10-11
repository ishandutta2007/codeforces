//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll maxm = 5e6 + 100;
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

ll n, a[maxn];
ll cnt[maxm];
pll ok[maxm];


int main(){
    fast_io;
    
    cin >> n;
    for(ll i = 0; i < n; i++){
    	cin >> a[i];
    	cnt[a[i]]++;
	}
	vector<ll> vec;
	for(ll i = 0; i < maxm; i++){
		if(cnt[i] > 1) vec.pb(i);
		if(Sz(vec) > 1) break;
	}
	if(Sz(vec) > 1){
		ll x = -1, y = -1, z = -1, w = -1;
		for(ll i = 0; i < n; i++){
			if(a[i] == vec[0]){
				if(x == -1) x = i;
				else z = i;
			}
			if(a[i] == vec[1]){
				if(y == -1) y = i;
				else w = i;
			}
		}
		cout << "YES\n";
		cout << x + 1 << " " << y + 1 << " " << z + 1 << " " << w + 1 << "\n";
		return 0;
	}
	if(Sz(vec) == 1){
		vector<ll> v2;
		for(ll i = 0; i < n; i++){
			if(a[i] == vec[0]){
				v2.pb(i);
			}
		}
		if(Sz(v2) > 3){
			cout << "YES\n";
			cout << v2[0] + 1 << " " << v2[1] + 1 << " " << v2[2] + 1 << " " << v2[3] + 1 << "\n";
			return 0;
		}
		ok[vec[0] + vec[0]] = Mp(v2[0], v2[1]);
		a[v2[0]] = -1;
		if(Sz(v2) == 3){
			a[v2[1]] = -1;
		}
	}
	for(ll i = 0; i < n; i++){
		if(a[i] == -1) continue;
		for(ll j = i + 1; j < n; j++){
			if(a[j] == -1) continue;
			ll x = a[i] + a[j];
			if(ok[x].F + ok[x].S){
				cout << "YES\n";
				cout << ok[x].F + 1 << " " << ok[x].S + 1 << " " << i + 1 << " " << j + 1 << "\n";
				return 0;
			}
			ok[x] = Mp(i, j);
		}
	}
	cout << "NO\n";
 
    return 0;
}