#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200100;
int n,ci;
vector<int>g[N],path[N];
int whos[N],price[N],par[N];
int a[500][500];

void dfs(int u,int emp,int idx){
	if(idx+1>=path[emp].size()){
		par[emp]=u;
		return;
	}
	for(auto v:g[u])
		if(price[v]==path[emp][idx]&&a[emp][whos[v]]<=price[v]){
			dfs(v,emp,idx+1);
			return;
		}
	g[u].push_back(ci);
	price[ci]=path[emp][idx];
	whos[ci]=emp;
	par[ci]=u;
	++ci;
	dfs(ci-1,emp,idx+1);
}

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	cin>>n;ci=n+1;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>a[i][j];
	vector<int>nodes(n);
	for(int i=0;i<n;++i)path[i].resize(n);
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			path[i][j]=a[i][j];
	for(int i=0;i<n;++i)sort(path[i].begin(),path[i].end());
	for(int i=0;i<n;++i)path[i].erase(unique(path[i].begin(),path[i].end()),path[i].end());
	for(int i=0;i<n;++i)reverse(path[i].begin(),path[i].end());
	for(int i=0;i<n;++i)price[i]=a[i][i];
	price[n]=*max_element(path[0].begin(),path[0].end());
	for(int i=0;i<n;++i)dfs(n,i,1);
	cout<<ci<<endl;
	for(int i=0;i<ci;++i)cout<<price[i]<<" ";cout<<endl;
	cout<<n+1<<endl;
	for(int i=0;i<ci;++i)if(i!=n)cout<<i+1<<" "<<par[i]+1<<endl;
}