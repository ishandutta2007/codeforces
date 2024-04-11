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
const int N=3e5+99;
int n,deg[N],m,x,y,v,ans[N];
vector<int> g[N];
set <int> s;
void change(int x,int sr){
	s.erase(x);
	ans[x]=!sr;
	deg[x]=g[x].size()-deg[x];
	f(i,0,g[x].size()){
		if(ans[g[x][i]]==sr){
			if(--deg[g[x][i]]==1)
				s.erase(g[x][i]);
		}
		else{
			if(++deg[g[x][i]]==2)
				s.insert(g[x][i]);
		}
	}
}
int main(){
	cin>>n>>m;
	f(i,0,m){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	f(i,1,n+1){
		deg[i]=g[i].size();
		if(deg[i]>1)
			s.insert(i);
	}
	while(!s.empty()){
		v=*(s.rbegin());
		change(v,ans[v]);
	}
	f(i,1,n+1)
		cout<<ans[i];
}