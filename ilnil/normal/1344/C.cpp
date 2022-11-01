#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=2e5+5;
int n,m,x,y,ts,can;
int bz[N],bz2[N];
vector<int>e[N],e2[N];
int cnt;
char ans[N];
void dfs(int x){
	bz[x]=2;
	for(int i:e[x])
		if(bz[i]==2)can=0;else
		if(!bz[i])dfs(i);
	bz[x]=1;
}
void col(int x){
	bz[x]=1;
	for(int i:e[x])if(!bz[i])
		col(i);
}
void col2(int x){
	bz2[x]=1;
	for(int i:e2[x])if(!bz2[i])
		col2(i);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	fo(i,1,m)cin>>x>>y,e[x].pb(y),e2[y].pb(x);
	can=1;
	fo(i,1,n)if(!bz[i])dfs(i);
	if(!can)printf("-1\n");
	else{
		fo(i,1,n)bz[i]=bz2[i]=0;
		fo(i,1,n){
			if(!bz[i]&&!bz2[i]){
				++cnt;
				ans[i]='A';
			}else
				ans[i]='E';
			if(!bz[i])col(i);
			if(!bz2[i])col2(i);
		}
		printf("%d\n",cnt);
		fo(i,1,n)putchar(ans[i]);
	}
}