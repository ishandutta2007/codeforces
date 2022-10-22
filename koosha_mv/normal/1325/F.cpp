#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=1e5+9;
int n,m,x,y,p,mark[N],deg[N],dis[N],masir[N];
vector<int> g[N],ans,dor;
queue<int> q;
void dfs(int x,int dist){
	dis[x]=dist;
	masir[dist]=x;
	mark[x]=1;
	f(i,0,g[x].size()){
		if(!mark[g[x][i]]){
			dfs(g[x][i],dist+1);
			return ;
		}
	}
	int v,mn=1e9;
	f(i,0,g[x].size()){
		if(dis[g[x][i]]!=0 && dis[g[x][i]]<mn)
			mn=dis[g[x][i]],v=g[x][i];
	}
	dor.pb(v);
	for(int i=dist;masir[i]!=v;i--)
		dor.pb(masir[i]);
}
void del(int x){
	mark[x]=1;
	f(i,0,g[x].size()){
		if(!mark[g[x][i]]){
			deg[g[x][i]]--;
			if(deg[g[x][i]]==p-1)
				q.push(g[x][i]);
		}
	}
}
int main(){
	cin>>n>>m;
	f(i,0,m){
		Gett(x,y);
		deg[x]++,deg[y]++;
		g[x].pb(y);
		g[y].pb(x);
	}
	p=sqrt(n);
	p+=(p*p<n)-1;
	f(i,1,n+1)
		if(g[i].size()<p)
			q.push(i);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(!mark[u]){
			mark[u]=1;
			ans.pb(u);
			f(i,0,g[u].size()){
				if(!mark[g[u][i]])
					del(g[u][i]);
			}
		}
	}
	if(ans.size()>=p+1){
		cout<<"1"<<endl;
		f(i,0,p+1)
			cout<<ans[i]<<" ";
	}
	else{
		cout<<"2"<<endl;
		f(i,1,n+1){
			if(!mark[i]){
				dfs(i,1);
				break;
			}
		}
		cout<<dor.size()<<endl;
		f(i,0,dor.size())
			cout<<dor[i]<<" ";
	}
}