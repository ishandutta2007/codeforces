#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,m,t,u,v,mark0[N],mark1[N],vis[N];
vector<int> ans,g[N];

void clear(){
	ans.clear();
	f(i,1,n+1) g[i].clear();
	f(i,1,n+1) mark1[i]=mark0[i]=vis[i]=0;
}

int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		clear();
		f(i,0,m){
			Gett(u,v);
			g[u].pb(v);
			g[v].pb(u);
		}
		f(i,1,n+1){
			if(mark0[i]==0){
				vis[i]=1;
				if(mark1[i])
					f(j,0,g[i].size())
						mark0[g[i][j]]=1;
				else
					f(j,0,g[i].size())
						mark1[g[i][j]]=1;
			}
		}
		f(i,1,n+1)
			if(!vis[i])
				ans.pb(i);
		cout<<ans.size()<<endl;
		f(i,0,ans.size())
			cout<<ans[i]<<" ";
		cout<<endl;
	}
}