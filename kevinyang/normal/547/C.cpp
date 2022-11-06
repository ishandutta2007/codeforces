#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	vector<int>factor(1000005,(int)1e18);
	for(int i = 2; i<=1000000; i++){
		for(int j = i; j<=1000000; j+=i){
			factor[j] = min(factor[j],i);
		}
	}
	vector<bool>vis(n+1);
	vector<int>freq(1000005);
	int cnt = 0;
	int ans = 0;
	while(q--){
		int idx;
		cin >> idx;
		if(vis[idx]){
			int v = arr[idx];
			int k = arr[idx];
			set<int>s;
			while(k!=1){
				s.insert(factor[k]);
				k/=factor[k];
			}
			vector<int>a;
			for(int nxt: s){
				a.push_back(nxt);
			}
			int len = a.size();
			for(int i = 1; i<(1<<len); i++){
				int v = 1;
				for(int j = 0; j<len; j++){
					if(i&(1<<j)){
						v*=a[j];
					}
				}
				if(__builtin_popcount(i)%2==1)ans-=freq[v]-1;
				else ans+=freq[v]-1;
				freq[v]--;
			}
			vis[idx] = false;
			cnt--;
		}
		else{
			int v = arr[idx];
			int k = arr[idx];
			set<int>s;
			while(k!=1){
				s.insert(factor[k]);
				k/=factor[k];
			}
			vector<int>a;
			for(int nxt: s){
				a.push_back(nxt);
			}
			int len = a.size();
			for(int i = 1; i<(1<<len); i++){
				int v = 1;
				for(int j = 0; j<len; j++){
					if(i&(1<<j)){
						v*=a[j];
					}
				}
				if(__builtin_popcount(i)%2==1)ans+=freq[v];
				else ans-=freq[v];
				freq[v]++;
			}
			cnt++;
			vis[idx] = true;
		}
		cout << cnt*(cnt-1)/2-ans << "\n";
	}
	return 0;
}