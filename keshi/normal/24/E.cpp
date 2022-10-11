#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef double ld;

const ll maxn = 5e5 + 100;

#define pb push_back


ll n, x[maxn], v[maxn];

bool isval(ld t){
	ld m = 1e10;
	bool f = 0;
	for(ll i = n - 1; i > -1; i--){
		if(v[i] < 0){
			m = min(m, x[i] + v[i] * t);
			f = 1;
		}
		else if(f){
			if(x[i] + v[i] * t >= m){
				return 1;
			}
		}
	}
	return 0;
}

bool check(){
	bool f = 0;
	for(ll i = n - 1; i > -1; i--){
		if(v[i] < 0){
			f = 1;
		}
		else if(f){
			return 0;
		}
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cout << fixed << setprecision(15);
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> x[i] >> v[i];
	}
	
	ld l = 0, r = 1e10, mid;
	
	if(check()){
		cout << -1;
		return 0;
	}
	
	for(ll i = 0; i < 70; i++){
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