#include<algorithm>
#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n,mark[200099],a[200099],ans[200099];
vector<int> g[200009],l;
int dfs(vector<int> v,int dis){
	if(v.size()==0) return 0;
	vector<int> v2;
	f(i,0,v.size()){
		f(j,0,g[v[i]].size()){
			if(mark[g[v[i]][j]]==0){
				v2.pb(g[v[i]][j]);
				mark[g[v[i]][j]]=dis;
			}
		}
	}
	dfs(v2,dis+1);
}
int main(){
	cin>>n;
	f(i,0,n){
		cin>>a[i];
		if(i+a[i]<n)
			g[i+a[i]].pb(i);
		if(i-a[i]>=0)
			g[i-a[i]].pb(i);
	}
	f(i,0,n){
		if((i+a[i]<n && a[i+a[i]]%2!=a[i]%2)||(i-a[i]>=0 && a[i-a[i]]%2!=a[i]%2)){
			mark[i]=1;
			l.pb(i);
		}
	}
	dfs(l,2);
	f(i,0,n) cout<<mark[i]-(mark[i]==0)<<" ";
}