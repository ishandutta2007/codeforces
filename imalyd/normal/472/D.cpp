#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define no {puts("NO");return 0;}
#define yes {puts("YES");return 0;}
const ll N=2005,N2=4000005;
ll rd(){
	ll a=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
	return a;
}
struct edge{
	ll a,b,v;
};
bool cmp(edge a,edge b){
	return a.v<b.v;
}
ll n,d[N][N],f[N],t,m,vis[N];
edge e[N2];
vector<int> v[N];
ll myabs(ll a){
	if(a>>63)return -a;return a;
}
ll find(ll a){
	if(!f[a])return a;
	return f[a]=find(f[a]);
}
ll dfs(ll s,ll a,ll dep){
	if(d[s][a]!=dep)return 1;
	vis[a]=1;
	for(ll i=0;i<v[a].size();i++){
		ll b=v[a][i];
		if(!vis[b]&&dfs(s,b,dep+d[a][b]))return 1;
	}
	return 0;
}
int main(){
	//freopen("input.txt","r",stdin);
	cin>>n;
	for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++)d[i][j]=rd();
	for(ll i=1;i<n;i++)for(ll j=i+1;j<=n;j++)if(d[i][j]!=d[j][i])no;
	for(ll i=1;i<n;i++)for(ll j=i+1;j<=n;j++)if(!d[i][j])no;
	for(ll i=1;i<=n;i++)if(d[i][i])no;
	for(ll i=1;i<n;i++)for(ll j=i+1;j<=n;j++)e[++t]=(edge){i,j,d[i][j]};
	sort(e+1,e+t+1,cmp);
	for(ll i=1;m<n-1;i++){
		ll a=e[i].a,b=e[i].b;
		ll x=find(a),y=find(b);
		if(x!=y)f[x]=y,m++,v[a].push_back(b),v[b].push_back(a);
	}
	/*for(ll i=1;i<=n;i++){
		for(ll j=0;j<v[i].size();j++)cout<<v[i][j]<<' ';
		cout<<endl;
	}*/
	for(ll i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(dfs(i,i,0))no;
	}
	yes;
}