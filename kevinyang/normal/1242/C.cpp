#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int,int>hm;
bool comp(pair<int,int>a, pair<int,int>b){
	return hm[a.first] < hm[b.first];
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int k;
	cin >> k;
	vector<vector<int>>arr(k+1);
	vector<int>sz(k+1);
	vector<int>sum(k+1);

	int total = 0;
	for(int i = 1; i<=k; i++){
		cin >> sz[i];
		for(int j = 0; j<sz[i]; j++){
			int x;
			cin >> x;
			hm[x] = i;
			arr[i].push_back(x);
			sum[i]+=x;
			total+=x;
		}
	}
	if(total%k!=0){
		cout << "No\n";
		return 0;
	}
	int rq = total/k;
	vector<int>dp(1<<k);
	vector<vector<pair<int,int>>>ans(1<<k);
	set<int>vis;
	for(int i = 1; i<=k; i++){
		for(int nxt: arr[i]){
			if(vis.find(nxt)!=vis.end())continue;
			vector<bool>visind(k+1);
			visind[i] = true;
			vis.insert(nxt);
			vector<int>vals; vals.push_back(0); vals.push_back(nxt);
			map<int,int>idx;
			idx[nxt] = 1;
			int cur = nxt;
			while(true){

				
				int want = cur+rq-sum[hm[cur]];
				//cerr << "nae " << cur << " " << want << "\n";
				vis.insert(want);
				if(idx[want]>0){
					//cerr << "nae\n";
					int mask = 0;
					vector<pair<int,int>>arrans;
					for(int j = idx[want]; j<vals.size()-1; j++){
						arrans.push_back({vals[j+1],hm[vals[j]]});
						mask^=(1<<(hm[vals[j]]-1));
					}
					arrans.push_back({want,hm[vals[vals.size()-1]]});
					mask^=(1<<(hm[vals[vals.size()-1]]-1));
					dp[mask] = 1;
					ans[mask] = arrans;
					break;
				}
				if(hm[want]==0)break;
				if(visind[hm[want]])break;

				idx[want] = idx.size();
				visind[hm[want]] = true;
				vis.insert(cur);
				cur = want;
				vals.push_back(cur);
			}
		}
	}
	/*
	for(int i = 0; i<(1<<k); i++){
		if(dp[i]){
			cout << i << "\n";
			for(pair<int,int>nxt: ans[i]){
				cout << nxt.first << " " << nxt.second << "\n";
			}
			cout << "\n";
		}
	}
	*/
	for(int i = 1; i<(1<<k); i++){
		for(int j = i; j>0; j=(j-1)&i){
			if(dp[j]&&dp[i^j]){
				dp[i] = 1;
				ans[i] = ans[j];
				for(pair<int,int>nxt: ans[i^j]){
					ans[i].push_back(nxt);
				}
			}
		}
	}
	if(dp[(1<<k)-1]){
		cout << "Yes\n";
		sort(ans[(1<<k)-1].begin(),ans[(1<<k)-1].end(),comp);
		for(pair<int,int>nxt: ans[(1<<k)-1]){
			cout << nxt.first << " " << nxt.second << "\n";
		}
	}
	else{
		cout << "No\n";
	}
	return 0;
}