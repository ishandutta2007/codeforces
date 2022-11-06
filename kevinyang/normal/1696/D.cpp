#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
struct Sparse{
	vector<int>logs;
	vector<vector<pair<int,int>>>dp;
	int ln;
	int size;
	void init(int n, vector<pair<int,int>>arr){
		size = n;
		logs.resize(n+1);
		dp.resize(n+1);
		ln = 0;
		for(int i = 1; i<=n; i*=2){
			logs[i] = ln; ln++;
		}
		for(int i = 1; i<=n; i++){
			dp[i].resize(ln+1);
			logs[i] = max(logs[i],logs[i-1]);
			dp[i][0] = arr[i];
		}
		for(int i = 1; i<=ln; i++){
			for(int j = 1; j+(1<<i)-1<=n; j++){
				dp[j][i] = min(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
			}
		}
	}
	pair<int,int> query(int l, int r){
		int lg = logs[r-l+1];
		return min(dp[l][lg],dp[r-(1<<lg)+1][lg]);
	}
};
struct Sparse2{
	vector<int>logs;
	vector<vector<pair<int,int>>>dp;
	int ln;
	int size;
	void init(int n, vector<pair<int,int>>arr){
		size = n;
		logs.resize(n+1);
		dp.resize(n+1);
		ln = 0;
		for(int i = 1; i<=n; i*=2){
			logs[i] = ln; ln++;
		}
		for(int i = 1; i<=n; i++){
			dp[i].resize(ln+1);
			logs[i] = max(logs[i],logs[i-1]);
			dp[i][0] = arr[i];
		}
		for(int i = 1; i<=ln; i++){
			for(int j = 1; j+(1<<i)-1<=n; j++){
				dp[j][i] = max(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
			}
		}
	}
	pair<int,int> query(int l, int r){
		int lg = logs[r-l+1];
		return max(dp[l][lg],dp[r-(1<<lg)+1][lg]);
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<pair<int,int>>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i].first;
			arr[i].second = i;
		}
		Sparse2 sparse2;
		Sparse sparse;
		sparse.init(n,arr);
		sparse2.init(n,arr);
		int i = 1; int cnt = 0;
		while(i<n){
			int i1 = 0; int r1 = 0;
			int i2 = 0; int r2 = 0;
			if(arr[i].first!=1){
				int r = n;
				if(arr[i].first!=n){
					int low = i; int high = n+1; int mid = (low+high)/2;
					while(low+1<high){
						if(sparse2.query(i,mid).first>arr[i].first){
							high = mid;
						}
						else{
							low = mid;
						}
						mid = (low+high)/2;
					}
					r = low;
				}
				pair<int,int>p = sparse.query(i,r); r1 = r;
				i1 = p.second;
			}
			if(arr[i].first!=n){
				int r = n;
				if(arr[i].first!=1){
					int low = i; int high = n+1; int mid = (low+high)/2;
					while(low+1<high){
						if(sparse.query(i,mid).first<arr[i].first){
							high = mid;
						}
						else{
							low = mid;
						}
						mid = (low+high)/2;
					}
					r = low;
				}
				pair<int,int>p = sparse2.query(i,r); r2 = r;
				i2 = p.second;
			}
			i = max(i1,i2);
			//cerr << i << " ";
			cnt++;
		}
		cout << cnt << "\n";

	}
	return 0;
}