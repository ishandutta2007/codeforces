//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, x, l[maxn], mx, e, k;

map<ll, ll> cnt;

vector<ll> a, v1, v2;

vector<pll> v;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> x;
		if(cnt[x] == 0){
			v2.pb(x);
		}
		cnt[x]++;
	}
	
	while(!v2.empty()){
		v1 = v2;
		v2.clear();
		for(ll i = 0; i < v1.size(); i++){
			a.pb(v1[i]);
			cnt[v1[i]]--;
			if(cnt[v1[i]]){
				v2.pb(v1[i]);
			}
		}
	}
	
	for(ll i = 0; i < a.size(); i++){
		cnt[a[i]]++;
		l[cnt[a[i]]] = i + 1;
	}
	
	for(ll i = 1; i <= n; i++){
		if(l[i] == 0) l[i] = n;
		if(l[i] / i >= i){
			if((l[i] / i) * i > mx){
				mx = (l[i] / i) * i;
				e = i;
			}
		}
	}
	
	cnt.clear();
	
	for(ll i = 0; i < mx; i++){
		cnt[a[i]]++;
	}
	
	for(map<ll, ll>::iterator i = cnt.begin(); i != cnt.end(); i++){
		v.pb({i -> S, i -> F});
	}
	
	sort(v.begin(), v.end(), greater<pll>());
	
	a.clear();
	
	for(ll i = 0; i < v.size(); i++){
		for(ll j = 0; j < v[i].F; j++){
			a.pb(v[i].S);
		}
	}
	
	cout << mx << '\n' << e << " " << mx / e << '\n';
	
	for(ll i = 0; i < e; i++){
		k = (i * (1 - e) + 10 * mx) % mx;
		for(ll j = 0; j < mx / e; j++){
			cout << a[k] << " ";
			k += e;
			if(k > mx){
				k -= mx;
			}
		}
		cout << '\n';
	}
	
	return 0;
}