#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, m, p[20], ptr;
vector<ll> ans;

bool adj(ll t){
	ll a = pow(2, t) + p[t] * pow(2, t + 1);
	bool f;
	if(a <= m){
		p[t]++;
		ans.push_back(a);
		return 1;
	}
	if(t == 0){
		return 0;
	}
	f = adj(t - 1);
	return adj(t - 1) && f;
}

int main(){
	cin >> n >> m;
	
	while(n){
		if(n % 2){
			if(!adj(ptr)){
				cout << -1;
				return 0;
			}
		}
		n /= 2;
		ptr++;
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	return 0;
}