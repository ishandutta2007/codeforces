#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops cout<<"!"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=2e5+99;
int t,n,m,x,y,dist[N],k,mx,an,cnt,st[N],ft[N],paren[N],a[N];
vector<int> g[N];
void dfs1(int x,int par,int dis){
	paren[x]=par;
	st[x]=cnt++;
	dist[x]=dis;
	f(i,0,g[x].size()){
		if(g[x][i]!=par)
			dfs1(g[x][i],x,dis+1);
	}
	ft[x]=cnt;
}
bool check_par(int x,int y){
	if(st[x]<=st[y] && st[y]<=ft[x]) return 1;
	return 0;
}
bool check(int x){
	f(i,0,k){
		if(check_par(a[i],x)==0 && check_par(paren[a[i]],x)==0){
		//	cout<<a[i]<<endl;
			return 0;
		}
	}
	return 1;
}
int main(){
	Gett(n,m);
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs1(1,0,0);
	f(i,0,m){
		cin>>k;
		mx=0;
		f(j,0,k){
			cin>>a[j];
			if(dist[a[j]]>mx) mx=dist[a[j]],an=a[j];
		}
		if(check(an)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}