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
const int N=2e5+99;

int n,x,y,mx,d1,d2,masir[N],dia[N],mark[N];
ll sumans,t;
vector<int> g[N];
vector<pair<int,int> > ans;

void Get_max_height(int x,int par,int h){
	if(h>mx)
		mx=h,d1=x;
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			Get_max_height(g[x][i],x,h+1);
}

void Get_diametr(int x,int par,int dist){
	if(dist>mx)
		mx=dist,d2=x,t=mx+1;
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			Get_diametr(g[x][i],x,dist+1);
}

void found_diametr(int x,int par,int dist){
	masir[dist]=x;
	if(x==d2){
		f(i,0,dist+1)
			dia[i]=masir[i],mark[masir[i]]=1;
	}
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			found_diametr(g[x][i],x,dist+1);
}

void solve(int x,int dis,int anss,int y,int rt){
	mark[x]=1;
	f(i,0,g[x].size()){
		if(!mark[g[x][i]])
			solve(g[x][i],dis+1,anss,y,rt);
	}
	if(x!=rt){
		ans.pb(make_pair(x,y));
		sumans+=1ll*(dis+anss);
	}
}

void solve_diametr(){
	f_(i,t-1,1)
		ans.pb(make_pair(dia[i],d1));
}

int main(){
	cin>>n;
	
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	
	Get_max_height(1,0,0);mx=0;
	Get_diametr(d1,0,0);
	found_diametr(d1,0,0);
	
	f(i,0,t){
		if(i<t/2)
			solve(dia[i],0,t-i-1,d2,dia[i]);
		else
			solve(dia[i],0,i,d1,dia[i]);
	}
	
	solve_diametr();
	
	cout<<sumans+t*(t-1)/2<<endl;
	f(i,0,ans.size())
		cout<<ans[i].F<<" "<<ans[i].S<<" "<<ans[i].F<<endl;
}