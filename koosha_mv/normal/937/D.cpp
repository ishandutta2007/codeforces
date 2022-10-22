#include <bits/stdc++.h>
#include<algorithm>
#define salamkhoobichwtori 1e17
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
ll ver[200009][2],chip,masir[200009],deg[200009],n,m,e,x,l,draw,mark[200009];
vector<int> g[200009];
int dfs1(int x,int dis){
	ver[x][dis%2]=1;
	masir[dis]=x;
	if(deg[x]==0 && dis%2==1 && l==0){
		cout<<"Win"<<endl;
		f(i,0,dis+1)
			cout<<masir[i]<<" ";
		l=1;}
	f(i,0,g[x].size()){
		if(mark[g[x][i]]==1)
				draw=1;
		if(ver[g[x][i]][(dis+1)%2]==0){
			mark[g[x][i]]=1;
			dfs1(g[x][i],dis+1);
			mark[g[x][i]]=0;
		}
	}
}
int main(){
	cin>>n>>m;
	f(i,1,n+1){
		cin>>e;
		f(j,0,e){
			cin>>x;
			g[i].push_back(x);
			deg[i]++;}}
	cin>>chip;mark[chip]=1;
	dfs1(chip,0);
	if(l==1)return 0;
	if(draw) cout<<"Draw";
	else cout<<"Lose";
	return 0;
}