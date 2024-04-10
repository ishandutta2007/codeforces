#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
const int mxn = 100005;
struct node{
	int w;
	vector<int>a;
};
bool comp(node a, node b){
	return a.w<b.w;
}
int sq = 400;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	map<int,bitset<mxn > >hm;
	map<int,vector<int>>idx;
	set<int>st;
	map<int,int>freq;
	vector<vector<int>>arr(n,vector<int>(m));
	vector<int>w(n);
	vector<node>a(n);
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> arr[i][j];
		}
		cin >> w[i];
		a[i].a = arr[i];
		a[i].w = w[i];
	}
	sort(a.begin(),a.end(),comp);
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			idx[a[i].a[j]].push_back(i);
			st.insert(a[i].a[j]);
			freq[a[i].a[j]]++;
		}
	}
	for(int nxt: st){
		if(freq[nxt]>=sq){
			bitset<mxn >bs;
			for(int ind: idx[nxt]){
				bs[ind] = 1;
			}
			hm[nxt] = bs;
		}
	}
	int ans = (int)1e18;
	for(int i = 0; i<n; i++){
		bitset<mxn >bs;
		for(int j = 0; j<m; j++){
			if(freq[a[i].a[j]]>=sq){
				bs|=hm[a[i].a[j]];
			}
			else{
				for(int nxt: idx[a[i].a[j]]){
					bs[nxt] = 1;
				}
			}
		}
		bs.flip();
		int val = bs._Find_first();
		//cout << val << "\n";
		if(val>=n)continue;
		ans = min(ans,a[i].w+a[val].w);
	}
	if(ans==(int)1e18){
		cout << "-1\n";
		return 0;
	}
	cout << ans << "\n";
	return 0;
}