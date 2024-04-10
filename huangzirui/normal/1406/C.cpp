#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=200010;
struct edge{
	int next,to;
}e[maxn*2];
int head[maxn],len;
void add(int x,int y){
	e[++len]={head[x],y};
	head[x]=len;
}
int i,j,k,n,m,T,is,size[maxn],w[maxn],ans;
void dfs(int now,int fa){
	w[now]=size[now]=1;
	for(int i=head[now];i;i=e[i].next){
		int u=e[i].to;
		if(u==fa)continue;
		dfs(u,now);
		size[now]+=size[u];
		w[now]=max(w[now],size[u]);
	}
	if(size[now]==1 && !is)is=now,size[now]=w[now]=0,printf("%d %d\n",now,fa);
//	cout<<"now-"<<now<<' '<<w[now]<<endl;
	w[now]=max(w[now],n-1-size[now]);
//	cout<<"now-"<<now<<' '<<w[now]<<endl;
	if(w[now]<w[ans])ans=now;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	w[0]=1e9;
	while(T--){
		memset(head,0,sizeof(head));len=0;
		is=ans=0;
		cin>>n;
		for(i=1;i<n;i++){int x,y;x=read();y=read();add(x,y);add(y,x);}
		dfs(1,0);
		printf("%d %d\n",is,ans);
	}
}