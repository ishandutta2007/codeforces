#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+99,Max=2e8;

int n,m,k,u,v,w,p,t=1,ans,a[10],vis[50],mark[N];
vector<pair<int,int> > go[N],gi[N];
ll adj[50];

void add_edge(int x,int y){
	adj[x]|=(1ll<<y);
	adj[y]|=(1ll<<x);
	p++;
}
void calc(){
	for(a[1]=1;a[1]<2;a[1]++)
	for(a[2]=1;a[2]<3;a[2]++)
	for(a[3]=1;a[3]<4;a[3]++)
	for(a[4]=1;a[4]<5;a[4]++)
	for(a[5]=1;a[5]<6;a[5]++)
	for(a[6]=1;a[6]<7;a[6]++)
	for(a[7]=1;a[7]<8;a[7]++)
	for(a[8]=1;a[8]<9;a[8]++)
	for(a[9]=1;a[9]<10;a[9]++){
		ll mask=0,ad=0;
		f(i,1,10){
			mask+=(1ll<<i*(i-1)/2+a[i]);
			ad|=adj[i*(i-1)/2+a[i]];
		}
		if((ad&mask)==0)
			ans++;
	}
}

main(){
	cin>>n>>m>>k;
	f(i,0,m){
		Gett(u,v);
		gett(w);
		go[u].pb(mp(w,v));
		gi[v].pb(mp(w,u));
	}
	f(i,1,n+1){
		sort(go[i].begin(),go[i].end());
		f(j,0,go[i].size())
			mark[go[i][j].F]=j+1;
	}
	f(i,1,n+1){
		vector<int> v;
		fill(vis,vis+50,0);
		if(go[i].size()==0) return cout<<-1,0;
		f(j,0,gi[i].size()){
			int siz=go[gi[i][j].S].size();
			if(vis[siz*(siz-1)/2+mark[gi[i][j].F]]==1)
				adj[siz*(siz-1)/2+mark[gi[i][j].F]]|=(1ll<<siz*(siz-1)/2+mark[gi[i][j].F]);
			if(!vis[siz*(siz-1)/2+mark[gi[i][j].F]]){
				v.pb(siz*(siz-1)/2+mark[gi[i][j].F]);
				vis[siz*(siz-1)/2+mark[gi[i][j].F]]++;
			}
		}
		if(45<sz(v)) cout<<"FUCK"<<endl;
		f(j,0,v.size())
			f(k,0,j)
				add_edge(v[k],v[j]);
	}
	calc();
	f(i,k+1,10) t*=i;
	cout<<ans/t<<endl;
}