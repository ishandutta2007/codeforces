#include <bits/stdc++.h>
using namespace std;
#define int long long
struct BIT{
	vector<int>arr;
	int size;
	void init(int n){
		size = n;
		arr.resize(n+5);
	}
	void update(int x, int val){
		for(int a = x; a<=size; a+=a&-a){
			arr[a]+=val;
		}
	}
	int query(int x){
		int sum = 0;
		for(int a = x; a>0; a-=a&-a){
			sum+=arr[a];
		}
		return sum;
	}
	void change(int x, int val){
		int v = query(x)-query(x-1);
		update(x,val-v);
	}
	int query(int x, int y){//inclusive
		return query(y)-query(x-1);
	}
};
const int mxn = 100005;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<vector<int>>arr(n+1,vector<int>(m+1));
	vector<vector<pair<int,int>>>idx(100005);
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			cin >> arr[i][j];
			idx[arr[i][j]].push_back({i,j});
		}
	}
	int ans = 0;
	if(true){
		BIT bit;
		bit.init(mxn);
		BIT bit2;
		bit2.init(mxn);
		for(int t = 1; t<=100000; t++){
			for(pair<int,int>nxt: idx[t]){
				bit.update(nxt.first,nxt.first);
				bit2.update(nxt.first,1);
			}
			for(pair<int,int>nxt: idx[t]){
				int v = bit2.query(nxt.first-1)*nxt.first-bit.query(nxt.first-1);
				ans+=v;
			}
			for(pair<int,int>nxt: idx[t]){
				bit.update(nxt.first,-nxt.first);
				bit2.update(nxt.first,-1);
			}
		}
	}
	if(true){
		BIT bit;
		bit.init(mxn);
		BIT bit2;
		bit2.init(mxn);
		for(int t = 1; t<=100000; t++){
			for(pair<int,int>nxt: idx[t]){
				bit.update(nxt.second,nxt.second);
				bit2.update(nxt.second,1);
			}
			for(pair<int,int>nxt: idx[t]){
				int v = bit2.query(nxt.second-1)*nxt.second-bit.query(nxt.second-1);
				ans+=v;
			}
			for(pair<int,int>nxt: idx[t]){
				bit.update(nxt.second,-nxt.second);
				bit2.update(nxt.second,-1);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}