#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=100010;
int i,j,k,n,m,T,w[maxn],C[maxn];
struct edge{
	int next,to;
}a[maxn*2];
int head[maxn],len;
void add(int x,int y){
	a[++len]={head[x],y};
	head[x]=len;
}
priority_queue<int>Q;
ll ans=0;
void dfs(int now,int fa){
	C[now]=(now!=1);
	for(int i=head[now];i;i=a[i].next){
		int u=a[i].to;
		if(u==fa)continue;
		++C[now];
		if(C[now]>1)Q.push(w[now]);
		dfs(u,now);
	}
//	cout<<"dfs.."<<now<<" C="<<C[now]<<endl;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;while(!Q.empty())Q.pop();ans=0;
		for(i=1;i<=n;i++)w[i]=read(),ans+=w[i];
		for(i=1;i<n;i++){
			int x=read(),y=read();
			add(x,y);add(y,x);
		}dfs(1,0);
		cout<<ans;
		for(i=1;i<n-1;i++){
			ans+=Q.top();Q.pop();
			printf(" %lld",ans);
		}puts("");
		for(i=1;i<=n;i++)head[i]=0;len=0;
	}
	return 0;
}