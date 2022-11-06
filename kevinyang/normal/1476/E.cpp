#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m,k;
	cin >> n >> m >> k;
	unordered_map<string,int>hm;
	unordered_map<string,int>ind;
	vector<string>arr(n+1);
	set<string>s;
	for(int i = 0; i<n; i++){
		string str;
		cin >> str;
		s.insert(str);
		ind[str] = i+1;
		arr[i+1] = str;
	}
	unordered_map<string,vector<string>>adj;
	for(int t = 0; t<m; t++){
		string str;
		cin >> str;
		int idx;
		cin >> idx;
		bool f = false;
		for(int i = 0; i<(1<<k); i++){
			string str2 = str;
			for(int j = 0; j<k; j++){
				if(i&(1<<j)){
					str2[j] = '_';
				}
			}
			if(s.find(str2)!=s.end()){
				if(ind[str2]==idx){
					f = true;
					continue;
				}
				adj[arr[idx]].push_back(str2);
			}
		}
		if(!f){
			cout << "NO\n";
			return 0;
		}
	}
	unordered_map<string,int>indegrees;
	for(string cur: s){
		for(string nxt: adj[cur]){
			indegrees[nxt]++;
		}
	}
	queue<string>q;
	vector<string>ans;
	int vis = 0;
	for(string nxt: s){
		if(indegrees[nxt]==0){
			q.push(nxt);
			ans.push_back(nxt);
			vis++;
		}
	}
	while(!q.empty()){
		string cur = q.front(); q.pop();
		for(string nxt: adj[cur]){
			indegrees[nxt]--;
			if(indegrees[nxt]==0){
				q.push(nxt);
				ans.push_back(nxt);
				vis++;
			}
		}
	}
	if(vis==n){
		cout << "YES\n";
		for(string nxt: ans){
			cout << ind[nxt] << " ";
		}
		cout << "\n";
	}
	else{
		cout << "NO\n";
	}
	return 0;
}