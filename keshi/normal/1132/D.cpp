#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;

#define pb push_back


ll n, k, a[maxn], b[maxn], t[maxn];

vector<ll> v[maxn];

ll cal(ll i){
	return t[i] / b[i] + 1;
}

bool isval(ll x){
	ll cnt = 0;
	for(ll i = 1; i <= k; i++){
		v[i].clear();
	}
	for(ll i = 0; i < n; i++){
		t[i] = a[i];
		if(cal(i) <= k){
			v[cal(i)].pb(i);
		}
	}
	for(ll i = 1; i <= k; i++){
		for(ll j = 0; j < v[i].size(); j++){
			while(cal(v[i][j]) == i){
				t[v[i][j]] += x;
				cnt++;
				if(cnt > i){
					return 0;
				}
			}
			if(cal(v[i][j]) <= k){
				v[cal(v[i][j])].pb(v[i][j]);
			}
		}
	}
	return 1;
}

int main(){
	cin >> n >> k;
	k--;
	ll cnt = 0;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	for(ll i = 0; i < n; i++){
		cin >> b[i];
		t[i] = a[i];
		if(cal(i) <= k){
			v[cal(i)].pb(i);
		}
	}
	for(ll i = 1; i <= k; i++){
		if(i - cnt < v[i].size()){
			cout << -1;
			return 0;
		}
		cnt += v[i].size();
	}
	ll l = -1, r = 1e13, mid;
	while(r - l > 1){
		mid = (l + r) / 2;
		if(isval(mid)){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	cout << r;
	return 0;
}