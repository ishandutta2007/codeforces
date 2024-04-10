#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#define M 998244853

int i,j,k,n,m,t,ord[1550],yes[1550],vis[1550],fa[1550],res[1550],it;
bitset<1505> f1[1550],f2[1550],sb,f,cur;
ll tmp;
vector<int> v[1550];
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
struct sb{
	int a[1550],id;
	ll hsh;
	bool operator<(const sb x)const{
		return (hsh==x.hsh)?id<x.id:hsh<x.hsh;
	}
}s1[1550],s2[1550];

void dfs(int x){
	vis[x]=1;
	if(k){return;}
	if(yes[x]){k=x;return;}
	for(auto i:v[x]){
		if(!vis[i]){fa[i]=x;dfs(i);}
	}
}

int main(){
	ios::sync_with_stdio(0);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		s1[i].id=i;
		tmp=1;
		for(j=1;j<=m;j++){
			scanf("%d",&s1[i].a[j]);
			s1[i].hsh=su(s1[i].hsh,s1[i].a[j]*tmp%M);
			tmp=tmp*19260817%M;
		}
	}
	
	for(i=1;i<=n;i++){
		s2[i].id=i;
		tmp=1;
		for(j=1;j<=m;j++){
			scanf("%d",&s2[i].a[j]);
			s2[i].hsh=su(s2[i].hsh,s2[i].a[j]*tmp%M);
			tmp=tmp*19260817%M;
		}
	}
	sort(s1+1,s1+n+1);
	sort(s2+1,s2+n+1);
	for(i=1;i<=n;i++){
		if(s1[i].hsh!=s2[i].hsh){puts("-1");return 0;}
		ord[s2[i].id]=s1[i].id;
		s1[i].hsh=s2[i].hsh=0;
	}
	sort(s1+1,s1+n+1);
	sort(s2+1,s2+n+1);
	for(i=1;i<=m;i++){
		yes[i]=1;
		for(j=2;j<=n;j++){
			if(s2[j].a[i]==s2[j-1].a[i]){
				f2[i][j-1]=1;
			}
			if(s2[j].a[i]<s2[j-1].a[i]){
				f1[i][j-1]=1;
			}
		}
	}
	for(i=2;i<=n;i++){
		if(ord[i]<ord[i-1]){sb[i-1]=1;}
		cur[i-1]=1;
	}
	t=m;
	while(t--){
		for(i=1;i<=m;i++){
			if(vis[i]){continue;}
			f=cur&f1[i];
			if(f.count()==0){
				cur&=f2[i];
				res[++it]=i;vis[i]=1;
			}
		}
	}
	f=(cur&sb);
	if(f.count()>0){puts("-1");return 0;}
	printf("%d\n",it);
	for(i=it;i>=1;i--){
		printf("%d ",res[i]);
	}
}