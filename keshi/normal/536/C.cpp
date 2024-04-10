//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll eps = 1e-5;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()


ll n, x[maxn], y[maxn];
pair<pll, ll> a[maxn];
vector<ll> vec;
bool vis[maxn];

ld get(ll i, ll j){
	return 1.0 * (y[i] - y[j]) / (x[j] - x[i]);
}

int main(){
    fast_io;

	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i].F.F >> a[i].F.S;
		a[i].F.S *= -1;
		a[i].S = i + 1;
	}
	sort(a, a + n);
	for(ll i = 0; i < n; i++){
		x[i] = a[i].F.F;
		y[i] = -a[i].F.S;
	}
	vec.pb(0);
	for(ll i = 1; i < n; i++){
		if(x[i] == x[i - 1]){
			continue;
		}
		while(Sz(vec) > 1){
			ll k = vec.back(), j = vec[Sz(vec) - 2];
			if((y[k] - y[j]) * (x[k] - x[i]) * y[i] * x[j] > (y[i] - y[k]) * (x[j] - x[k]) * y[j] * x[i]){
				vec.pop_back();
			}
			else break;
		}
		vec.pb(i);
	}
	vector<ll> ans;
	for(ll i = Sz(vec); i--;){
		vis[vec[i]] = 1;
		if(i > 0 && (y[vec[i]] >= y[vec[i - 1]] && x[vec[i]] != x[vec[i - 1]])){
			break;
		}
	}
	for(ll i = 0; i < n; i++){
		if(i > 0 && a[i].F == a[i - 1].F) vis[i] = vis[i - 1];
		if(vis[i]) ans.pb(a[i].S);
	}
	sort(all(ans));
	for(ll i : ans){
		cout << i << " ";
	}

    return 0;
}