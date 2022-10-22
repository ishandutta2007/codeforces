#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=2e5+9;
int n,m,k,cnt,t,p,x,y,mark[N];
vector<int> g[N],ans;
void dfs(int x,int pr){
	mark[x]=1;
	ans.pb(x);
	f(i,0,g[x].size()){
		if(!mark[g[x][i]]){
			dfs(g[x][i],x);
			ans.pb(x);
		}
	}
}
int main(){
	cin>>n>>m>>k;
	f(i,0,m){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	t=(2*n+(k-1))/k;
	dfs(1,0);
	f(i,0,k){
		cout<<max(1,min(t,int(ans.size()-p)))<<" ";
		if(p==ans.size()) cout<<1;
		f(i,p,min(p+t,int(ans.size())))
			cout<<ans[i]<<" ";
		cout<<endl;
		p=min(p+t,int(ans.size()));
	}
}