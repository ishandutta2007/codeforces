#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

void solve(){
	ll N; cin >> N;
	vll v(N*2);
	for(auto &x: v){
		cin >> x;
	}
	sort(v.rbegin(), v.rend());
	ll s = 0;
	for(int i = 0; i < 2*N; i+=2){
		if(i > 0 && v[i] == v[i-2]){
			cout << "NO\n";
			return;
		}
		if(v[i] != v[i+1]){
			cout << "NO\n";
			return;
		}
	//	cout << v[i]-s <<" ";
		if((v[i]-s)%(2*N-i) || v[i]-s <= 0){

			cout << "NO\n";
			return;
		}else{
			s+=(v[i]-s)/(N-i/2);
		}
	}
	cout << "YES\n";
	return;
}

int main(){
	int T = 1;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}