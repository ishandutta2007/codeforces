#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		set<int>s;
		map<int,int>hm;
		int cur = n;
		for(int i = 2; i*i<=n; i++){
			while(cur%i==0){
				s.insert(i);
				hm[i]++;
				cur/=i;
			}
		}
		if(cur>1){
			s.insert(cur);
			hm[cur]++;
		}
		cur = 1;
		pair<int,int>ans = {0,0};
		for(int nxt: s){
			ans = max(ans,{hm[nxt],nxt});
		}
		cout << ans.first << "\n";
		for(int i = 1; i<ans.first; i++){
			cout << ans.second << " ";
			n/=ans.second;
		}
		cout << n << "\n";
	}
	return 0;
}