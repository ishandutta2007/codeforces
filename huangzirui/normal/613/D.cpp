#include <bits/stdc++.h>
#define ll long long
#define Mid ((L+R)>>1)
using namespace std;
typedef pair<int,int> pii;
inline int read(){
	char c;int x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;return x;
}
const int maxn=100010;
int id,i,j,k,n,m;
struct edge{
	int next,to;
}a[maxn*2],e[maxn*2];
int head[maxn],len;
int head2[maxn],len2;
void add(int x,int y){
	a[++len]={head[x],y};
	head[x]=len;
}
void add2(int x,int y){
	//cout<<x<<' '<<y<<endl;
	e[++len2]={head2[x],y};
	head2[x]=len2;
	e[++len2]={head2[y],x};
	head2[y]=len2;
}
int F[maxn][21],deep[maxn],dfn[maxn],cnt;
void dfs(int now,int fa){
	F[now][0]=fa;deep[now]=deep[fa]+1;
	dfn[now]=++cnt;
	for(int i=head[now];i;i=a[i].next){
		int u=a[i].to;
		if(u==fa)continue;
		dfs(u,now);
	}
}
void LCA(){
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n;i++)
			F[i][j]=F[F[i][j-1]][j-1];
}
int lca(int x,int y){
	if(deep[x]<deep[y])swap(x,y);
	for(int j=20;j>=0;j--)
		if(deep[F[x][j]]>=deep[y])
			x=F[x][j];
	if(x==y)return x;
	for(int j=20;j>=0;j--)
		if(F[x][j]!=F[y][j])
			x=F[x][j],y=F[y][j];
	return F[x][0];
}
bool cmp(int x,int y){
	return dfn[x]<dfn[y];
}
int is[maxn],h[maxn],Cnt;
int Sta[maxn],top;
int dp[maxn],g[maxn],can;
void dfs2(int now,int fa){
	//cout<<now<<' '<<fa<<' '<<is[now]<<' '<<id<<endl;
	for(int i=head2[now];i;i=e[i].next){
		int u=e[i].to;
		if(u==fa)continue;
		dfs2(u,now);
	}
	dp[now]=g[now]=0;
	if(is[now]==id){
		for(int i=head2[now];i;i=e[i].next){
			int u=e[i].to;
			if(is[u]==id && abs(deep[u]-deep[now])==1)can=-1;
			if(u==fa)continue;
			dp[now]+=dp[u]+g[u];
		}g[now]=1;
	}else{
		int Sum=0;
		for(int i=head2[now];i;i=e[i].next){
			int u=e[i].to;
			if(u==fa)continue;
			dp[now]+=dp[u];
			if(g[u])++Sum;
		}
		if(Sum<=1)g[now]=Sum;
		else dp[now]++;
	}
	head2[now]=0;
}
int main() {
	cin>>n;
	for(i=1;i<n;i++){
		int x,y;
		x=read();y=read();
		add(x,y);add(y,x);
	}
	dfs(1,0);LCA();
	cin>>m;
	for(id=1;id<=m;id++){
		k=read();Cnt=can=0;
		for(j=1;j<=k;j++){
			int x;
			x=read();
			is[x]=id;
			h[++Cnt]=x;
		}
		sort(h+1,h+1+Cnt,cmp);
		Sta[top=1]=1;
		//cout<<"i="<<i<<endl;
		for(j=1;j<=Cnt;j++){
			if(h[j]==1)continue;
			//cout<<"j="<<j<<" h="<<h[j]<<" "<<top<<endl;
			int l=lca(Sta[top],h[j]);
			/*
			cout<<"j="<<j<<" h="<<h[j]<<" "<<Sta[top]<<" l="<<l<<endl;
			for(int h=1;h<=top;h++)cout<<Sta[h]<<' ';cout<<endl;
			*/
			while(deep[Sta[top-1]]>deep[l]){
				add2(Sta[top-1],Sta[top]);
				top--;
			}
			if(Sta[top]!=l){
				if(Sta[top-1]==l)add2(Sta[top-1],Sta[top]),top--;
				else add2(l,Sta[top]),Sta[top]=l;
			}
			Sta[++top]=h[j];
		}
		while(top>1){
			add2(Sta[top-1],Sta[top]);
			top--;
		}
		dfs2(1,0);
		if(!can)printf("%d\n",dp[1]);
		else puts("-1");
		len2=0;
	}
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}