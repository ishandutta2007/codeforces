#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		if(k==1){
			for(int i = 1; i<=n; i++){
				cout << i << " ";
			}
			cout << "\n";
			continue;
		}
		bool f = false;
		if(n>60)f = true;//number of permutations of 1-n that exist is 2^(n-1)
		else if((1LL<<(n-1))>=k)f = true;
		if(!f){
			cout << "-1\n";
			continue;
		}
		vector<int>vals(n+1);
		for(int i = n; i>=max(n-60,1LL); i--){
			if(i>=n-1)vals[i] = 1;
			else vals[i] = vals[i+1]*2;
		}
		/*
		cout << "vals: ";
		for(int i = 1; i<=n; i++){
			cout << vals[i] << " ";
		}
		cout << "\n";
		*/
		vector<int>ans;
		set<int>s;
		for(int i = 1; i<=n; i++){
			s.insert(i);
		}
		int last = 1;
		for(int i = 1; i<=n; i++){
			if(n-i>=61){
				ans.push_back(i);
				s.erase(i);
				continue;
			}
			if(vals[i]>=k){
				ans.push_back(i);
				s.erase(i);
				continue;
			}
			last = i;
			break;
		}
		//cout << s.size() << "\n";
		for(int i = last; i<=n; i++){
			if(k<=vals[i]){
				//cout << "nae " << i << "\n";
				ans.push_back(i); s.erase(i);
				int cur = i;
				while(s.size()&&*s.lower_bound(cur-1)==cur-1){
					cur--;
					ans.push_back(cur); s.erase(cur);
				}
			}
			else{
				k-=vals[i];
			}
		}
		for(int nxt: s){
			ans.push_back(nxt);
		}
		//cout << ans.size() << "\n";
		for(int nxt: ans){
			cout << nxt << " ";
		}
		cout << "\n";
	}
	return 0;
}