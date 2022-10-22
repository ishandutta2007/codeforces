#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
const int N=1099;
ll n,t,k1,k2,mark[N],x,v,ans,mark2[N],y;
vector<int> g[N];
int dfs(int x,int par){
	if(mark[x]==1){
		ans=x;
		return 0;
	}
	f(i,0,g[x].size()){
		if(g[x][i]!=par)
			dfs(g[x][i],x);
	}
}
int main(){
	cin>>t;
	f(pop,0,t){
		f(i,0,n+1){
			mark[i]=0,mark2[i]=0;g[i].clear();
		}
		cin>>n;
		f(i,1,n){
			cin>>x>>y;
			g[y].pb(x);
			g[x].pb(y);
		}
		cin>>k1;
		f(i,0,k1){
			cin>>x;
			mark[x]=1;
		}
		cin>>k2;
		f(i,0,k2){
			cin>>x;
			mark2[x]=1;
		}
		cout<<"B "<<x<<endl;
		cin>>v;
		ans=0;
		dfs(v,0);
		cout<<"A "<<ans<<endl;
		cin>>v;
		if(mark2[v]==1)
			cout<<"C "<<ans<<endl;
		else
			cout<<"C "<<-1<<endl;
	}

}