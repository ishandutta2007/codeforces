#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
vector<ll> g[5009];
int mark[5009],k=1,y,x,n,m,a[5009][2];
int dfs(int x,int y){
	mark[x]=1;
	f(i,0,g[x].size()){
		if(g[x][i]==y){
			k=2;return 0;}
		if(mark[g[x][i]]==0)
			dfs(g[x][i],y);
	}
}
int main(){
	cin>>n>>m;
	f(i,0,m){
		cin>>x>>y;
		a[i][0]=x,a[i][1]=y;
		g[x].push_back(y);}
	f(i,1,n+1){
		f(j,0,5002)
			mark[j]=0;
		dfs(i,i);
	}
	cout<<k<<endl;
	f(i,0,m)
		cout<<min((a[i][0]<a[i][1])+1,k)<<" ";
}