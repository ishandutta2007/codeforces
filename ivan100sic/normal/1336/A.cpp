#include <bits/stdc++.h>
using namespace std;
int n,k,s[1<<20],v[1<<20];
basic_string<int> e[1<<20];
void dfs(int x,int p,int d=0){
	s[x]=1;
	for (int y : e[x])if(y-p)dfs(y,x,d+1),s[x]+=s[y];
	v[x-1]=d-s[x]+1;
}
int main(){
	ios::sync_with_stdio(!cin.tie(0));
	cin>>n>>k;
	for (int i=1,u,v;i<n;i++,cin>>u>>v,e[u]+=v,e[v]+=u);
	dfs(1,1);
	nth_element(v,v+n-k,v+n);
	cout<<accumulate(v+n-k,v+n,0ll)<<'\n';
}