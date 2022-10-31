#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,vis[100500],it;
vector<pair<ll,ll> > v[100500];
ll f[100500];

void fuck1(){
	memset(vis,0,sizeof(vis));
	priority_queue<pair<ll,ll> >q;
	for(i=1;i<=n;i++)q.push({-f[i],i});
	while(!q.empty()){
		auto [w,id]=q.top();q.pop();
		if(vis[id])continue;
		w=-w;
		vis[id]=1;f[id]=w;
		for(auto [j,k]:v[id]){
			if(vis[j])continue;
			q.push({-f[id]-k,j});
		}
	}
}

ll a[100500],b[100500],res;
#define wt(x,y) (a[x]*(y)+b[x])
struct SB{
	#define md ((l+r)/2)
	#define ls (id*2)
	#define rs (ls+1)
	int f[400500];
	void add(int id,int l,int r,int w){
		if(!f[id]){f[id]=w;return;}
		if(wt(w,md)<=wt(f[id],md))swap(w,f[id]);
		if(l==r)return;
		if(wt(w,l)<=wt(f[id],l))add(ls,l,md,w);
		if(wt(w,r)<=wt(f[id],r))add(rs,md+1,r,w);
	}
	void get(int id,int l,int r,int x){
		if(l<=x&&x<=r&&f[id])res=min(res,wt(f[id],x));
		if(l==r)return;
		if(x<=md)get(ls,l,md,x);else get(rs,md+1,r,x);
	}
}sb;

void fuck2(){
	memset(sb.f,0,sizeof(sb.f));
	for(i=1;i<=n;i++){a[i]=-2*i;b[i]=f[i]+i*i;sb.add(1,1,n,i);}
	for(i=1;i<=n;i++){res=1e18;sb.get(1,1,n,i);f[i]=res+i*i;}
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>t;
	for(i=1;i<=n;i++)f[i]=1e18;
	f[1]=0;
	for(i=1;i<=m;i++){
		int j,k,w;
		cin>>j>>k>>w;
		v[j].push_back({k,w});
		v[k].push_back({j,w});
	}
	fuck1();
	while(t--){fuck2();fuck1();}
	for(i=1;i<=n;i++)cout<<f[i]<<' ';
}