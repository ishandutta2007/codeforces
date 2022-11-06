#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#endif

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);

	int n,k;cin>>n>>k;
	string a,b;cin>>a>>b;

	vector<vector<int>> adj(2*n);
	const int DONE=-1;
	//left wall
	for(int i=0;i<n;i++){
		if(a[i]=='X')continue;
		if(i-1>=0&&a[i-1]=='-')adj[i].push_back(i-1);
		if(i+1<n&&a[i+1]=='-')adj[i].push_back(i+1);
		if(i+k<n&&b[i+k]=='-')adj[i].push_back(n+i+k);
		else if(i+k>=n)adj[i].push_back(DONE);
	}
	//right wall
	for(int i=0;i<n;i++){
		if(b[i]=='X')continue;
		if(i-1>=0&&b[i-1]=='-')adj[n+i].push_back(n+i-1);
		if(i+1<n&&b[i+1]=='-')adj[n+i].push_back(n+i+1);
		if(i+k<n&&a[i+k]=='-')adj[n+i].push_back(i+k);
		else if(i+k>=n)adj[n+i].push_back(DONE);
	}

	//can you be at this vertex at this time?
	auto ok=[&](int v,int t){
		return t<=v%n;
	};

	vector<int> dist(2*n,-1);
	queue<int> q;
	q.push(0);
	dist[0]=0;

	while(!q.empty()){
		int u=q.front();
		// cerr<<"u is "<<u<<"\n";
		q.pop();
		for(int v:adj[u]){
			// cerr<<"chk "<<v<<"\n";
			if(v==DONE){
				cout<<"YES\n";
				return 0;
			}
			if(dist[v]==-1&&ok(v,dist[u]+1)){
				dist[v]=dist[u]+1;
				q.push(v);
				// cerr<<"pu "<<v<<"\n";
			}
		}
	}
	cout<<"NO\n";
}