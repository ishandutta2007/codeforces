#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define add(x,y)(x=(y+x)%mo)
using namespace std;
const int N=1e5+5,M=1e6+5,mo=1e9+7,mo2=998244353;
int n,p[N],sz[N],mx[N],id[N],ds;
int d[M],dd;
vector<int>e[N];
bool cmp(int x,int y){
	return mx[x]<mx[y]||mx[x]==mx[y]&&x<y;
}
void dfs(int x){
	sz[x]=1;mx[x]=1;
	for(int i:e[x]){
		dfs(i);
		sz[x]+=sz[i];
		mx[x]=max(mx[x],mx[i]+1);
	}
	sort(e[x].begin(),e[x].end(),cmp);
}
void dfs2(int x){
	id[++ds]=x;
	for(int i:e[x])dfs2(i);
}
void dfs3(int x){
	int la=0;
	for(int i:e[x]){
		fo(j,1,la)d[++dd]=i;
		dfs3(i);
		la=mx[i];
	}
}
int main(){
	cin>>n;
	fo(i,1,n-1)scanf("%d",&p[i]),e[p[i]].push_back(i);
	dfs(0);
	dfs2(0);
	dfs3(0);
	fo(i,1,n)printf("%d ",id[i]);printf("\n");
	printf("%d\n",dd);
	fo(i,1,dd)printf("%d ",d[i]);
}