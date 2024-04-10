//In the name of GOD
//Hello 2020
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

ll n, l[maxn], mn[maxn], mx[maxn], x, c, ans;

vector<ll> v, a;

bool f;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> l[i];
		cin >> mn[i];
		mx[i] = mn[i];
		f = 0;
		for(ll j = 1; j < l[i]; j++){
			cin >> x;
			if(x > mn[i]) f = 1;
			else mn[i] = x;
			mx[i] = max(mx[i], x);
		}
		if(f) c++;
		else v.pb(i);
	}
	
	for(ll i = 0; i < v.size(); i++){
		a.pb(mn[v[i]]);
	}
	
	sort(a.begin(), a.end());
	
	for(ll i = 0; i < v.size(); i++){
		if(mx[v[i]] > a.back()) ans += a.size();
		else ans += (lower_bound(a.begin(), a.end(), mx[v[i]]) - a.begin());
	}
	
	cout << ans + c * (2 * n - c);
	
	return 0;
}