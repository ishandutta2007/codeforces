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

ll n, a[maxn], b[maxn], s;
vector<pll> ans;

int main(){
	fast_io;
	
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	for(ll i = 0; i < n; i++){
		ll x;
		cin >> x;
		b[x] = i;
	}
	for(ll i = 0; i < n; i++){
		a[i] = b[a[i]];
	}
	for(ll i = 0; i < n; i++){
		ll x = -1;
		for(ll j = n; j--;){
			if(x != -1){
				if(a[j] >= x){
					swap(a[j], a[x]);
					s += x - j;
					ans.pb(Mp(j + 1, x + 1));
				}
			}
			if(a[j] == i) x = j;
		}
	}
	cout << s << "\n";
	cout << Sz(ans) << "\n";
	for(pll i : ans){
		cout << i.F << " " << i.S << "\n";
	}
	
	return 0;
}