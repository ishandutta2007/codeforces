#include <bits/stdc++.h>
#include<algorithm>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=1e6+10;
int t,n,a[N],mark[N],dist[N],pr[N],ans=1e9,u;
vector<int> v,g[N],p;
void bfs(int source){
	queue <int> q;
	q.push(source);
	f(i,0,p.size()) dist[p[i]]=-1;
	dist[source]=0;
	while(!q.empty()){
		u=q.front();
		q.pop();
		f(i,0,g[u].size()){
			if(dist[g[u][i]]==-1){
				q.push(g[u][i]);
				dist[g[u][i]]=dist[u]+1;
			}
			else if(dist[g[u][i]]>=dist[u])
				minm(ans,dist[g[u][i]]+dist[u]+1);
		}
	}
}
int main(){
	p.pb(1);
	f(i,2,N){
		if(pr[i]==0){
			p.pb(i);
			for(int j=i;j<N;j+=i)
				pr[j]=1;
		}
	}
	cin>>n;
	f(i,0,n){
		v.clear();
		cin>>a[i];
		for(int j=2;j*j<=a[i];j++){
			t=0;
			if(a[i]%j==0){
				while(a[i]%j==0)
					a[i]/=j,t++;
				if(t%2==1) v.pb(j);
				break;
			}
		}
		t=0;
		for(int j=2;j*j<=a[i];j++){
			while(a[i]%j==0)
				a[i]/=j,t++;
			if(t%2)
				v.pb(j);
		}
		if(a[i]>1) v.pb(a[i]);
		if(v.size()==2)
			g[v[0]].pb(v[1]),g[v[1]].pb(v[0]);
		if(v.size()==1){
			g[v[0]].pb(1);
			g[1].pb(v[0]);
		}
		if(v.size()==0)
			return cout<<1,0;
	}
	for(int i=0;p[i]<1000;i++)
		bfs(p[i]);
	if(ans>N) return cout<<-1,0;
	cout<<ans<<endl;
}