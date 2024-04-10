#include <bits/stdc++.h>
using namespace std;
#define int long long
struct DisjointSet{
	vector<int>parent,sz;
	int size;
	void init(int n){
		size = n;
		parent.resize(n+1); sz.resize(n+1);
		for(int i = 1; i<=n; i++){
			parent[i] = i;
			sz[i] = 1;
		}
	}
	int find(int x){
		if(parent[x]==x)return x;
		return find(parent[x]);
	}
	void Union(int x, int y){
		x = find(x); y = find(y);
		if(x==y)return;
		if(sz[x]<sz[y]){
			parent[x] = y;
			sz[y]+=sz[x];
		}
		else{
			parent[y] = x;
			sz[x]+=sz[y];
		}
	}
};
char other(char ch){
	if(ch=='W')return 'B';
	else return 'W';
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	s = s+s;
	if(true){
		set<char>st;
		set<char>st2;
		for(int i = 0; i<2*n; i++){
			if(i%2==0)st.insert(s[i]);
			else st2.insert(s[i]);
		}
		if(st.size()==1&&st2.size()==1){
			if(k%2==1){
				for(int i = 1; i<=n; i++){
					cout << s[i];
				}
			}
			else{
				for(int i = 0; i<n; i++){
					cout << s[i];
				}
			}
			return 0;
		}
	}
	DisjointSet ds;
	ds.init(2*n);
	for(int i = 1; i<2*n; i++){
		if(s[i-1]==s[i]){
			ds.Union(i,i+1);
		}
	}
	vector<int>good(2*n+1);
	for(int i = 1; i<=2*n; i++){
		if(ds.sz[ds.find(i)]>1){
			good[i] = 1;
		}
	}
	vector<char>ans(n+1);
	for(int i = 1; i<=2*n; i++){
		if(good[i]){
			int idx = i;
			if(idx>n)idx-=n;
			ans[idx] = s[i];
		}
	}
	vector<pair<int,char>>left(2*n+1,make_pair((int)1e18,'a'));
	vector<pair<int,char>>right(2*n+1,make_pair((int)1e18,'a'));
	vector<pair<int,char>>val(n+1,make_pair((int)1e18,'a'));
	if(true){
		int cur = -(int)1e18;
		char ch = 'a';
		for(int i = 1; i<=2*n; i++){
			if(good[i]){
				ch = s[i-1];
				cur = i;
				continue;
			}
			left[i] = {i-cur,ch};
		}
	}
	if(true){
		int cur = (int)1e18;
		char ch = 'a';
		for(int i = 2*n; i>=1; i--){
			if(good[i]){
				ch = s[i-1];
				cur = i;
				continue;
			}
			right[i] = {cur-i,ch};
		}
	}
	for(int i = 1; i<=2*n; i++){
		int idx = i; 
		if(idx>n)idx-=n;
		val[idx] = min(val[idx],right[i]);
		val[idx] = min(val[idx],left[i]);
	}
	for(int i = 1; i<=n; i++){
		if(good[i]||good[i+n]){
			cout << s[i-1];
		}
		else{
			if(k>=val[i].first){
				cout << val[i].second;
			}
			else if(k%2==val[i].first%2){
				cout << val[i].second;
			}
			else{
				cout << other(val[i].second);
			}
		}
	}
	cout << "\n";
	return 0;
}