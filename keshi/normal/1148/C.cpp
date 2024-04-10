//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e5 + 100;
const ll mod = 998244353;
const ll inf = 8e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, p[maxn], a[maxn];

vector<pll> ans;

bool f(ll i, ll j){
	if(i == j){
		return 1;
	}
	if(abs(i - j) * 2 >= n){
		ans.pb({i, j});
		swap(p[i], p[j]);
		a[p[i]] = i;
		a[p[j]] = j;
		return 1;
	}
	return 0;
}

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> p[i];
		a[p[i]] = i;
	}
	
	for(ll i = 1; i <= n; i++){
		if(!f(a[i], i)){
			if(f(a[i], 1)){
				if(!f(a[i], i)){
					f(a[i], n);
					f(a[i], i);
				}
				f(a[1], 1);
			}
			else{
				f(a[i], n);
				if(!f(a[i], i)){
					f(a[i], 1);
					f(a[i], i);
				}
				f(a[1], 1);
			}
		}
	}
	
	cout << ans.size() << endl;
	
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i].F << " " << ans[i].S << endl;
	}
	
	return 0;
}