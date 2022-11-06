#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		vector<int>rq(n);
		for(int i = 0; i<n; i++){
			cin >> rq[i];
		}
		vector<int>arr2(m);
		for(int i = 0; i<m; i++){
			cin >> arr2[i];
		}
		vector<int>same(n+1,-1);// index of a paint i that doesn't change lol
		for(int i = 0; i<n; i++){
			if(arr[i]==rq[i])same[arr[i]] = i;
		}
		vector<set<int>>reqs(n+1);//indices of planks that need to change to paint t
		for(int i = 0; i<n; i++){
			if(arr[i]!=rq[i])reqs[rq[i]].insert(i);
		}
		bool f = true;
		int used = -1;
		vector<int>ans(m);
		for(int i = m-1; i>=0; i--){
			if(reqs[arr2[i]].size()>0){
				used = *reqs[arr2[i]].begin();
				reqs[arr2[i]].erase(used);
				ans[i] = used;
			}
			else if(same[arr2[i]]!=-1){
				used = same[arr2[i]];
				ans[i] = same[arr2[i]];
			}
			else{
				if(used==-1)f = false;
				else ans[i] = used;
			}
		}
		for(int i = 1; i<=n; i++){
			if(reqs[i].size()>0)f = false;
		}
		if(f){
			cout << "YES\n";
			for(int i = 0; i<m; i++){
				cout << ans[i]+1 << " ";
			}
			cout << "\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}