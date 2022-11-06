#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>dis(501,(int)1e9);
vector<pair<int,int>>pre(501);
int n,k;
int queries = 0;
int f(int len, vector<int>ind){
	if(queries>500)assert(false);
	if(len==k){
		assert(ind.size()==k);
		cout << "? ";
		for(int nxt: ind){
			cout << nxt << " ";
		}
		cout << endl;
		int v;
		cin >> v;
		queries++;
		return v;
	}
	assert(ind.size()==len);
	vector<bool>vis(501);
	for(int nxt: ind){
		vis[nxt] = true;
	}
	int intsect = (pre[len].first+pre[len].second-len)/2;
	assert(intsect*2+len==pre[len].first+pre[len].second);
	int len1 = pre[len].first;
	int len2 = pre[len].second;
	vector<int>ind1;
	vector<int>ind2;
	for(int i = 0; i<len; i++){
		if(i<len1-intsect)ind1.push_back(ind[i]);
		else ind2.push_back(ind[i]);
	}
	int cur = 0;
	for(int i = 1; i<=n; i++){
		if(cur==intsect)break;
		if(!vis[i]){
			cur++;
			ind1.push_back(i);
			ind2.push_back(i);
			if(cur==intsect)break;
		}
	}
	assert(cur==intsect);
	int v1 = f(len1,ind1);
	int v2 = f(len2,ind2);
	return v1^v2;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> k;
	set<pair<int,int>>q;
	vector<bool>vis(n+1);
	dis[k] = 1;
	q.insert({1,k});
	while(q.size()){
		pair<int,int>p = *q.begin(); q.erase(p);
		if(vis[p.second])continue;
		vis[p.second] = true;
		for(int i = 1; i<=n; i++){
			if(!vis[i])continue;
			for(int j = 0; j<=min(i,p.second); j++){
				int rq = i+p.second-j;
				int rem = i+p.second-2*j;
				if(rq>n)continue;
				if(dis[p.second]+dis[i]<dis[rem]){
					dis[rem] = dis[p.second] + dis[i];
					pre[rem] = {p.second,i};
					q.insert({dis[rem],rem});
				}
			}
		}
	}
	if(dis[n]>500){
		cout << "-1" << endl;
		return 0;
	}
	vector<int>indices;
	for(int i = 1; i<=n; i++){
		indices.push_back(i);
	}
	int res = f(n,indices);
	cout << "! " << res << endl;
	cout << queries << "\n";
	return 0;
}