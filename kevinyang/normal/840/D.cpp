#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
int arr[300005];
pair<int,int>dp[20][300005][5];
vector<vector<int>>idx(300005);
int freq[300005];
void f(int l, int r, int layer){
	int m = (l+r)/2;
	if(r-l==1)return;
	if(true){
		set<pair<int,int>>s;
		for(int i = 0; i<5; i++){
			s.insert({0,i+1});
		}
		for(int i = m-1; i>=l; i--){
			freq[arr[i]]++;
			if(s.find({freq[arr[i]]-1,arr[i]})!=s.end()){
				s.erase({freq[arr[i]]-1,arr[i]});
				s.insert({freq[arr[i]],arr[i]});
			}
			else{
				if((*s.begin()).first<freq[arr[i]]){
					s.erase(s.begin());
					s.insert({freq[arr[i]],arr[i]});
				}
			}
			auto it = s.begin();
			for(int j = 0; j<5; j++){
				dp[layer][i][j] = *it;
				it++;
			}
		}
		for(int i = m-1; i>=l; i--){
			freq[arr[i]]--;
		}
	}
	if(true){
		set<pair<int,int>>s;
		for(int i = 0; i<5; i++){
			s.insert({0,i+1});
		}
		for(int i = m; i<r; i++){
			freq[arr[i]]++;
			if(s.find({freq[arr[i]]-1,arr[i]})!=s.end()){
				s.erase({freq[arr[i]]-1,arr[i]});
				s.insert({freq[arr[i]],arr[i]});
			}
			else{
				if((*s.begin()).first<freq[arr[i]]){
					s.erase(s.begin());
					s.insert({freq[arr[i]],arr[i]});
				}
			}
			auto it = s.begin();
			for(int j = 0; j<5; j++){
				dp[layer][i][j] = *it;
				it++;
			}
		}
		for(int i = m; i<r; i++){
			freq[arr[i]]--;
		}
	}
	f(l,m,layer+1);
	f(m,r,layer+1);
}
int query(int x, int l, int r){
	int cnt = lower_bound(idx[x].begin(),idx[x].end(),r+1)-lower_bound(idx[x].begin(),idx[x].end(),l);
	return cnt;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> q;
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
		idx[arr[i]].push_back(i);
	}
	f(1,n+1,0);
	while(q--){
		int l,r,k;
		cin >> l >> r >> k;
		if(l==r){
			cout << arr[l] << "\n";
		}
		else{
			int lx = 1; int rx = n+1;
			int layer = 0;
			int m = (lx+rx)/2;
			while(true){
				if(l>=m){
					lx = m;
				}
				else if(r<m){
					rx = m;
				}
				else{
					break;
				}
				layer++;
				m = (lx+rx)/2;
			}
			int ans = (int)1e18;
			for(int j = 0; j<5; j++){
				pair<int,int>p = dp[layer][l][j];
				if(query(p.second,l,r)>(r-l+1)/k){
					ans = min(ans,p.second);
				}
			}
			for(int j = 0; j<5; j++){
				pair<int,int>p = dp[layer][r][j];
				if(query(p.second,l,r)>(r-l+1)/k){
					ans = min(ans,p.second);
				}
			}
			if(ans==(int)1e18){
				cout << "-1\n";
			}
			else{
				cout << ans << "\n";
			}
		}
	}
	return 0;
}