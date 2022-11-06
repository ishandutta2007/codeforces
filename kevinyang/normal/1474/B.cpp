#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	vector<bool>prime(100000,true);
	prime[0] = prime[1] = false;
	set<int>s;
	for(int i = 2; i<100000; i++){
		if(!prime[i])continue;
		for(int j = i*i; j<100000; j+=i){
			prime[j] = false;
		}

		s.insert(i);
	}
	int t;
	cin >> t;
	while(t--){
		int d;
		cin >> d;
		int v1 = *s.lower_bound(d+1);
		int v2 = *s.lower_bound(v1+d);
		//cout << v1 << " " << v2 << "\n";
		cout << v1*v2 << "\n";
	}
	return 0;
}