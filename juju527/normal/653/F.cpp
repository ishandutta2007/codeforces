#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
int n;
char s[maxn];
int sum[maxn];
int lg[maxn];
int mn[maxn][19];
vector<int>c[2*maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int tot=1,last=1;
int to[maxn<<1][2],len[maxn<<1],nxt[maxn<<1];
int epos[maxn<<1];
void extend(int c,int id){
	int p=last,u=++tot;
	len[u]=len[p]+1;
	epos[u]=id;
	while(p&&to[p][c]==0){to[p][c]=u;p=nxt[p];}
	if(!p)nxt[u]=1;
	else{
		int d=to[p][c];
		if(len[d]==len[p]+1)nxt[u]=d;
		else{
			int v=++tot;
			len[v]=len[p]+1;
			to[v][0]=to[d][0];to[v][1]=to[d][1];
			nxt[v]=nxt[d];nxt[u]=nxt[d]=v;
			while(p&&to[p][c]==d){to[p][c]=v;p=nxt[p];}
		}
	}
	last=u;
	return ;
}
int get(int l,int r){
	int len=lg[r-l+1];
	return min(mn[l][len],mn[r-(1<<len)+1][len]);
}
struct Edge{
	int to,nxt;
}e[maxn<<1];
int cnt;
int head[maxn<<1];
void add(int u,int v){
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
	return ;
}
ll res=0;
void dfs(int x){
	if(!epos[x])epos[x]=0x3f3f3f3f;
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		dfs(tmp);
		epos[x]=min(epos[x],epos[tmp]);
	}
	int l=epos[x]-len[x],r=epos[x]-len[nxt[x]]+1;
	if(sum[r]-sum[epos[x]+1]<0)return ;
	while(l+1<r){
		int mid=l+((r-l)>>1);
		if(get(mid,epos[x])>=sum[epos[x]+1])r=mid;
		else l=mid;
	}
	int co=sum[epos[x]+1]+n;
	if(r<=epos[x]-len[nxt[x]]){
		int lt=lower_bound(c[co].begin(),c[co].end(),r)-c[co].begin();
		int rt=upper_bound(c[co].begin(),c[co].end(),epos[x]-len[nxt[x]])-c[co].begin();
		res+=rt-lt;
	}
	return ;
}
int main(){
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)extend(s[i]=='(',i);
	for(int i=n;i>=1;i--)sum[i]=sum[i+1]+(s[i]==')'?1:-1);
	for(int i=1;i<=n;i++)c[sum[i]+n].push_back(i);
	lg[0]=-1;
	for(int i=1;i<=n;i++)lg[i]=lg[i>>1]+1,mn[i][0]=sum[i];
	for(int j=1;j<=lg[n];j++)
		for(int i=1;i<=n-(1<<j)+1;i++)
			mn[i][j]=min(mn[i][j-1],mn[i+(1<<j-1)][j-1]);
	memset(head,-1,sizeof(head));
	for(int i=2;i<=tot;i++)add(nxt[i],i);
	dfs(1);
	printf("%lld\n",res);
    return 0;
}