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
		vector<int>arr(n+1);
		vector<int>psa(n+1);
		vector<int>pre(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
			psa[i] = psa[i-1]+arr[i];
			pre[i] = max(pre[i-1],psa[i]);
		}
		for(int i = 0; i<m; i++){
			int x;
			cin >> x;
			if(psa[n]<=0&&pre[n]<x){
				cout << "-1 ";
				continue;
			}
			int runs = 0;
			if(psa[n]>0&&x>pre[n])runs = (x-pre[n]+psa[n]-1)/psa[n];
			x-=runs*psa[n];
			int ind = lower_bound(pre.begin(),pre.end(),x)-pre.begin();
			cout << runs*n+ind-1 << " ";
		}
		cout << "\n";
	}
	return 0;
}