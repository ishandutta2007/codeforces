#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=3e5+5,mo=1e9+7;
int n,x,y,rt,mn,mx;
int d[N],fa[N],sum[N];
vector<int>e[N];
bool leaf[N];
void dfs(int x){
	for(int i:e[x])if(i!=fa[x]){
		fa[i]=x;
		d[i]=d[x]+1;
		sum[x]+=leaf[i];
		dfs(i);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	fo(i,2,n)cin>>x>>y,e[x].pb(y),e[y].pb(x);
	fo(i,1,n)if(e[i].size()==1)leaf[i]=1;
	fo(i,1,n)if(leaf[i]){
		rt=i;break;
	}
	dfs(rt);
	int all=0;
	fo(i,1,n)if(leaf[i]&&(d[i]&1))++all;
	if(!all)mn=1;else mn=3;
	mx=n-1;
	fo(i,1,n)if(sum[i]>1)mx-=sum[i]-1;
	fo(i,1,n)if(leaf[i]&&d[i]==2){
		--mx;break;
	}
	printf("%d %d\n",mn,mx);
}