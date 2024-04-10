#include <bits/stdc++.h>
using namespace std;
#define int long long
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
vector<int> f(int x){
	vector<int>low; vector<int>high;
	for(int i = 1; i*i<=x; i++){
		if(i*i==x){
			low.push_back(i);
		}
		else if(x%i==0){
			low.push_back(i);
			high.push_back(x/i);
		}
	}
	reverse(high.begin(),high.end());
	for(int nxt: high){
		low.push_back(nxt);
	}
	return low;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	/*
	1/2 chance for a random element chosen to be part of the n/2 length sequence with the max gcd

	this means that the gcd will be a divisor of the random element chosen

	*/
	int t = 11;
	int mx = 0;
	while(t--){
		int idx = rng()%n;
		vector<int>factors = f(arr[idx]);
		unordered_map<int,int>hm;
		for(int i = 0; i<n; i++){
			int v = __gcd(arr[i],arr[idx]);
			hm[v]++;
		}
		for(int i = 0; i<factors.size(); i++){
			int cnt = 0;
			for(int j = i; j<factors.size(); j++){
				if(factors[j]%factors[i]==0){
					cnt+=hm[factors[j]];
				}
			}
			if(cnt>=(n+1)/2){
				mx = max(mx,factors[i]);
			}
		}
	}
	cout << mx << "\n";
	return 0;
}