#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<vector<int>>psa(k+1,vector<int>(n+1));
	for(int i = 1; i<=n; i++){
		for(int j = 0; j<=k; j++){
			psa[j][i]+=psa[j][i-1];
		}
		if(s[i-1]=='?')psa[k][i]++;
		else psa[s[i-1]-'a'][i]++;
	}
	int low = 0; int high = n+1; int mid = (low+high)/2;
	while(low+1<high){
		vector<int>dp(1<<k,(int)1e18);
		vector<vector<int>>vals(k+1);
		for(int i = mid; i<=n; i++){
			for(int j = 0; j<k; j++){
				if(psa[j][i]-psa[j][i-mid]+psa[k][i]-psa[k][i-mid]==mid){
					vals[j].push_back(i);
				}
			}
		}
		dp[0] = 0;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
		pq.push({0,0});
		vector<bool>vis(1<<k);
		while(!pq.empty()){
			pair<int,int>cur = pq.top(); pq.pop();
			if(vis[cur.second])continue;
			vis[cur.second] = true;
			for(int j = 0; j<k; j++){
				if(!((1<<j)&cur.second)){
					auto it = lower_bound(vals[j].begin(),vals[j].end(),cur.first+mid);
					if(it==vals[j].end())continue;
					if(dp[cur.second^(1<<j)]>*it){
						dp[cur.second^(1<<j)] = *it;
						pq.push({*it,cur.second^(1<<j)});
					}
				}
			}
		}
		if(dp[(1<<k)-1]<=n){
			low = mid;
		}
		else{
			high = mid;
		}
		mid = (low+high)/2;
	}
	cout << low << "\n";
	return 0;
}