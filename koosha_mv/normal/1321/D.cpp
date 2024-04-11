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
#define mp make_pair
const int N=3e5+99;
int n,m,x,y,a[N],par[N],dis[N],mark[N],mn,mx,k;
vector<int> g[N],h,g2[N];
void bfs(vector<int> v,int dist){
	if(v.size()==0) return ;
	vector<int> s;
	f(i,0,v.size()){
		f(j,0,g[v[i]].size()){
			if(dis[g[v[i]][j]]==-1){
				dis[g[v[i]][j]]=dist+1;
				s.pb(g[v[i]][j]);
			}
		}
	}
	bfs(s,dist+1);
}
int main(){
	f(i,0,N) dis[i]=-1;
	cin>>n>>m;
	f(i,0,m){
		Gett(x,y);
		g[y].pb(x);
		g2[x].pb(y);
	}
	cin>>k;
	f(i,0,k) get(a[i]);
	dis[a[k-1]]=0;
	h.pb(a[k-1]);
	bfs(h,0);
	f(i,0,k-1){
		if(dis[a[i]]>dis[a[i+1]]){
			int p=0;
			f(j,0,g2[a[i]].size()){
				if(dis[g2[a[i]][j]]<dis[a[i]]) p++;
			}
			if(p>1)mx++;
		}
		else mx++,mn++;
	}

	cout<<mn<<" "<<mx;
}