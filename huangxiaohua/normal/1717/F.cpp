#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 100005
struct Dinic{
	int Q[N],d[N],L,R;
	int tot,cur[N],Head[N],Next[N];
	struct edge{int to,cap,flow;}W[N];
	void Init(){memset(Head,(tot=0)-1,sizeof(Head));}
	void Add(int x,int y,int cap){
		Next[tot]=Head[x];
		W[Head[x]=tot++]={y,cap,0};
		Next[tot]=Head[y];
		W[Head[y]=tot++]={x,0,0};
	}
	int BFS(int s,int t){
		memset(d,0,sizeof(d));
		d[Q[L=R=1]=s]=1;
		while(L<=R){
			int x=Q[L++];
			cur[x]=Head[x];
			for(int i=Head[x];~i;i=Next[i]){
				edge e=W[i];
				if(!d[e.to]&&e.flow<e.cap)
					d[Q[++R]=e.to]=d[x]+1;
			}
		}
		return d[t];
	}
	int DFS(int x,int t,int flow){
		if(x==t||!flow)return flow;
		int pre=flow,f;
		for(int &i=cur[x];~i;i=Next[i]){
			edge e=W[i];
			if(d[e.to]==d[x]+1&&(f=DFS(e.to,t,min(e.cap-e.flow,flow)))){
				W[i].flow+=f;W[i^1].flow-=f;
				if(!(flow-=f))return pre;
			}
		}
		return pre-flow;
	}
	ll Solve(int s,int t){
		ll res=0;
		while(BFS(s,t))res+=DFS(s,t,INT_MAX);
		return res;
	}
}di;

int i,j,k,n,m,t,a[N],b[N],w[N],su,bl[N],br[N];
int st,ed;

int main(){
	di.Init();
	cin>>n>>m;
	st=n+m+1;ed=n+m+2;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++){cin>>b[i];b[i]*=-1;}
	for(i=1;i<=m;i++){
		cin>>j>>k;
		bl[i]=j;br[i]=k;
		b[j]++;b[k]++;
		w[n+i]++;w[st]--;
		di.Add(n+i,j,1);
		di.Add(n+i,k,1);
	}
	for(i=1;i<=n;i++){
		if(!a[i])continue;
		if(b[i]&1){cout<<"NO";return 0;}
		w[i]-=b[i]/2;w[ed]+=b[i]/2;
	}
	for(i=1;i<=ed;i++){
		if(i<=n&&!a[i])di.Add(i,ed,1e9);
		if(!w[i])continue;
		if(w[i]<0)di.Add(i,n+m+3,-w[i]);else{su+=w[i];di.Add(0,i,w[i]);}
	}
	di.Add(ed,st,1e9);
	if(su!=di.Solve(0,n+m+3)){cout<<"NO";return 0;}
	cout<<"YES\n";
	for(i=1;i<=m;i++){
		for(j=di.Head[n+i];~j;j=di.Next[j]){
			auto [to,cap,flow]=di.W[j];
			if(to<1||to>n)continue;
			if(flow){
				if(to==br[i])swap(bl[i],br[i]);
				break;
			}
		}
		cout<<bl[i]<<' '<<br[i]<<'\n';
	}
}