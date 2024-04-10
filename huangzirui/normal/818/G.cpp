#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxm=200010,maxn=20000010,INF=100000;
struct edge{
	int next,to,w,c;
}e[maxm*2];
int head[maxn],len=-1;
void add(int x,int y,int z,int c){
	e[++len]={head[x],y,z,c};
	head[x]=len;
}
int Q[maxn],L,R;
int i,j,k,n,m,s,t,dis[maxn],vis[maxn],deep[maxn],Last[maxn],chs[maxn],sum[maxn];
bool spfa(){
	memset(dis,0x3f,sizeof(dis));dis[s]=0;
	L=R=1;Q[1]=s;sum[s]=INF;
	while(L<=R){
		int now=Q[L++];
		//cout<<"now="<<now<<' '<<dis[now]<<endl;
		vis[now]=0;
		for(int i=head[now];i!=-1;i=e[i].next){
			int u=e[i].to;
			//cerr<<now<<" -> "<<u<<endl;
			if(e[i].w==0)continue;
			if(dis[now]+e[i].c<dis[u]){
				dis[u]=dis[now]+e[i].c;
				sum[u]=min(sum[now],e[i].w);
				Last[u]=now;chs[u]=i;
				if(!vis[u])vis[u]=1,Q[++R]=u;
			}
		}
	}return dis[t]!=0x3f3f3f3f;
}
int w;
int a[maxn],last[maxn],is[maxn],is2[maxn],to[maxn];
int main(){
	memset(head,-1,sizeof(head));
	cin>>n;
	for(i=1;i<=n;i++)a[i]=read();
	for(i=n;i>=1;i--)last[i]=is[a[i]%7],is[a[i]%7]=i;
	for(i=1;i<=n;i++)add(i,i+n,1,-1),add(i+n,i,0,1);
	for(i=1;i<=n;i++){
		add(i+2*n,i,INF,0);
		add(i,i+2*n,0,0);
	}
	for(i=1;i<=n;i++)if(last[i]){
	//	cout<<i<<' '<<last[i]<<endl;
		add(i+n,last[i]+2*n,INF,0);
		add(last[i]+2*n,i+n,0,0);
		add(i+2*n,last[i]+2*n,INF,0);
		add(last[i]+2*n,i+2*n,0,0);
	}
	for(i=n;i>=1;i--){
		if(is2[a[i]+1]){
			add(i+n,is2[a[i]+1],INF,0);
			add(is2[a[i]+1],i+n,0,0);
		}
		if(is2[a[i]-1]){
			add(i+n,is2[a[i]-1],INF,0);
			add(is2[a[i]-1],i+n,0,0);
		}
		is2[a[i]]=i;
	}
	s=3*n+1;int s2=3*n+2;t=3*n+3;
	add(s,s2,4,0);
	add(s2,s,0,0);
	add(s2,t,4,0);
	add(t,s2,0,0);
	for(i=1;i<=n;i++)add(s2,i,INF,0),add(i,s2,0,0),add(i+n,t,INF,0),add(t,i+n,0,0);
	int flow=0,cost=0;
	while(spfa()){
		int now=t;
		flow+=sum[t];
//		cout<<"STOP "<<sum[t]<<' '<<s<<' '<<t<<endl<<endl;
		while(now!=s){
			int G=Last[now];
			e[chs[now]].w-=sum[t];
			e[chs[now]^1].w+=sum[t];
			cost+=sum[t]*e[chs[now]].c;
//			cout<<G<<" -> "<<now<<" chs="<<chs[now]<<endl;
			now=G;
		}
//		cout<<"FLOW="<<flow<<" COST="<<cost<<endl;
		//Sleep(1);
	}cout<<-cost<<endl;
}