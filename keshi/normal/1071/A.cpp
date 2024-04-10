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

ll a, b;
vector<ll> v1, v2;
bool f;

int main(){
    fast_io;

	cin >> a >> b;
	if(a > b) swap(a, b), f = 1;
	ll x = 1;
	while(a >= x){
		a -= x;
		v1.pb(x);
		x++;
	}
	if(a != 0){
		v1.erase(find(all(v1), x - a));
		v1.pb(x);
		if(b >= x - a){
			v2.pb(x - a);
			b -= x - a;
		}
		x++;
	}
	while(b >= x){
		b -= x;
		v2.pb(x);
		x++;
	}
	if(f) swap(v1, v2);
	cout << Sz(v1) << '\n';
	for(ll i : v1){
		cout << i << " ";
	}
	cout << '\n';
	cout << Sz(v2) << '\n';
	for(ll i : v2){
		cout << i << " ";
	}

    return 0;
}