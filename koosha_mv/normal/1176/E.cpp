#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=3e5;
ll n,m,ans1[N],s1,ans2[N],s2,mark[N],x,y,t;
vector<int> g[N];
void dfs(int x,int dis){
	mark[x]=1;
	if(dis%2==0) ans1[s1++]=x;
	else ans2[s2++]=x;
	f(i,0,g[x].size())
		if(mark[g[x][i]]==0) dfs(g[x][i],dis+1);
}
int main(){
	get(t);
	while(t--){
		f(i,0,n+2) g[i].clear(),mark[i]=0;
		Get(n,m);
		s1=s2=0;
		f(i,0,m){
			Get(x,y);
			g[x].pb(y);
			g[y].pb(x);
		}
		dfs(1,0);
		if(s1<s2){
			cout<<s1<<endl;
			f(i,0,s1) cout<<ans1[i]<<" ";
		}
		else{
			cout<<s2<<endl;
			f(i,0,s2) cout<<ans2[i]<<" ";
		}
		cout<<endl;
	}
}