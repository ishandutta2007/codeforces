#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
int mxans,ans,n,mark[201],x,y,mx,mx1,mx2;
vector<int> g[201];
int dfs(int x,int dis,int asli){
	mark[x]=1;
	mx=max(mx,dis);
	f(i,0,g[x].size()){
		if(mark[g[x][i]]==0){
			dfs(g[x][i],dis+1,asli);}}
}
int masir(int x){
	int t;
	mx1=0,mx2=0;
	f(i,0,g[x].size()){
		if(mark[g[x][i]]==0){
			mx=0;
			dfs(g[x][i],1,g[x][i]);
			t=mx;
			if(t>mx1){
				mx2=mx1;
				mx1=t;}
			else mx2=max(mx2,t);
		}
	}
}
int main(){
	cin>>n;
	f(i,0,n-1){
		cin>>x>>y;
		g[x].push_back(y),g[y].push_back(x);}
	f(i,1,n){
		f(j,i+1,n+1){
			f(k,0,201) mark[k]=0;
			mark[i]=1,mark[j]=1;
			masir(i);ans=mx1+mx2;
			masir(j);ans*=(mx1+mx2);
			mxans=max(mxans,ans);}
	}
	cout<<mxans;
}