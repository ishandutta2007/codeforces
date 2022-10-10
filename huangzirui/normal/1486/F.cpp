#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}

const int maxn=300010;
struct edge{
	int next,to;
}e[maxn*2];
int head[maxn],len;
void add(int x,int y){
	e[++len]={head[x],y};
	head[x]=len;
}
int i,j,k,n,m,T,Fa[maxn][21],deep[maxn];
ll w[maxn],s[maxn],xm[maxn];
map<pii,ll>M[maxn];
map<pii,ll>::iterator it;
void dfs(int now,int fa){
	deep[now]=deep[fa]+1;
	Fa[now][0]=fa;
	for(int i=head[now];i;i=e[i].next){
		int u=e[i].to;
		if(u==fa)continue;
		dfs(u,now);
	}
}
void init(){
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n;i++)
			Fa[i][j]=Fa[Fa[i][j-1]][j-1];
}
int lca(int x,int y){
	if(deep[x]>deep[y]);else swap(x,y);
	for(int j=20;j>=0;j--)
		if(deep[Fa[x][j]]>=deep[y])x=Fa[x][j];
	if(x==y)return x;
	for(int j=20;j>=0;j--)
		if(Fa[x][j]!=Fa[y][j])x=Fa[x][j],y=Fa[y][j];
	return Fa[x][0];
}
int jump(int x,int len){
	if(len<0)return x;
	//cout<<x<<' '<<len<<endl;
	for(int j=20;j>=0;j--){
		if(len>=(1<<j)){
			len-=(1<<j);
			x=Fa[x][j];
		}
	}
	//cout<<x<<endl;
	return x;
}

void work(int x,int y){
	int z=lca(x,y);
	int X=jump(x,deep[x]-deep[z]-1),Y=jump(y,deep[y]-deep[z]-1);
	w[x]++;w[y]++;w[z]--;w[Fa[z][0]]--;
	s[x]++;s[y]++;s[z]-=2;
	//cout<<x<<' '<<X<<' '<<y<<' '<<Y<<endl;
	xm[x]++;xm[X]--;
	xm[y]++;xm[Y]--;
	M[z][make_pair(min(X,Y),max(X,Y))]++;
}

void getans(int now,int fa){
	for(int i=head[now];i;i=e[i].next){
		int u=e[i].to;
		if(u==fa)continue;
		getans(u,now);
		w[now]+=w[u];
		s[now]+=s[u];
		xm[now]+=xm[u];
	}//cout<<"now="<<now<<' '<<xm[now]<<endl;
}

int main(){
	cin>>n;
	for(i=1;i<n;i++){
		int x,y;
		x=read();y=read();
		add(x,y);add(y,x);
	}
	dfs(1,0);
	init();
	cin>>m;
	for(i=1;i<=m;i++){
		int x=read(),y=read();
		work(x,y);
	}
	getans(1,0);
	ll ans=0;
	for(i=1;i<=n;i++){
		ans+=(1ll*w[i]*(w[i]-1))/2;
		for(int j=head[i];j;j=e[j].next){
			int u=e[j].to;
			if(u!=Fa[i][0]){
				ans-=(1ll*s[u]*(s[u]-1))/2;
				ans+=(1ll*xm[u]*(xm[u]-1))/2;
			}
		}
//		cout<<"i="<<i<<endl;
//		cout<<ans<<endl;
		ans-=(1ll*s[i]*(s[i]-1))/2;
//		cout<<ans<<endl;
		for(it=M[i].begin();it!=M[i].end();it++){
			pair<pii,ll>P=*it;
//			cout<<"P"<<P.first.first<<' '<<P.first.second<<' '<<' '<<P.second<<endl;
			if(P.first.first!=i && P.first.second!=i){
				ans+=(1ll*P.second*(P.second-1))/2;
			}
		}
	}cout<<ans<<endl;//
	return 0;
}