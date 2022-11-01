#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define P pair<int,int>
#define link(x,y)(e[x].push_back(P(y,++nn)),e[y].push_back(P(x,nn)))
using namespace std;
const int N=2e5+5;
int nn,n,x,y,du[N+N],mx,my,co[N*3],col;
vector<P>e[N+N];
bool vi[N+N];
void dfs(int x){
	vi[x]=1;
	for(;e[x].size();){
		P i=e[x].back();e[x].pop_back();
		if(co[i.second])continue;
		co[i.second]=1;
		dfs(i.first);
		co[i.second]=col=3-col;
	}
}
int main(){
	cin>>n;
	fo(i,1,n){
		scanf("%d%d",&x,&y);
		mx=max(mx,x);my=max(my,y);
		link(x,y+N);
	}
	int la=0;
	fo(i,1,mx)if(e[i].size()&1)link(i,mx+1);
	fo(i,N+1,N+my)if(e[i].size()&1)link(i,N+my+1);
	if(e[mx+1].size()&1)link(mx+1,N+my+1);
	col=1;
	fo(i,1,mx)if(!vi[i])dfs(i);
	fo(i,N+1,N+my)if(!vi[i])dfs(i);
	fo(i,1,n)putchar(co[i]==1?'b':'r');
}