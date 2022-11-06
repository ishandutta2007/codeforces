#include <bits/stdc++.h>
using namespace std;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int mxn = (int)1e7+5;
	vector<int>factor(mxn);
	vector<bool>prime(mxn,true);
	vector<int>primes;
	for(int i = 2; i<=(int)1e7; i++){
		if(prime[i])primes.push_back(i);
		if(i>(int)1e4)continue;
		for(int j = i*i; j<=(int)1e7; j+=i){
			prime[j] = false;
		}
	}
	//cerr << "nae\n";
	for(int i: primes){
		for(int j = i; j<=(int)1e7; j+=i){
			if(factor[j]==0)factor[j] = i;
		}
	}
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		set<int>s2;
		int ans = 1;
		for(int i = 1; i<=n; i++){
			set<int>s;
			int k = arr[i];
			while(k!=1){
				if(s.find(factor[k])!=s.end()){
					s.erase(factor[k]);
					arr[i]/=factor[k];
					arr[i]/=factor[k];
				}
				else{
					s.insert(factor[k]);
				}
				k/=factor[k];
			}
			if(s2.find(arr[i])!=s2.end()){
				s2.clear();
				ans++;
				s2.insert(arr[i]);
			}
			else{
				s2.insert(arr[i]);
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}