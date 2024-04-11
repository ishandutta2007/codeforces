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
#define F first
#define s second
ll x,y,n,m,q,mark[105][105],c,cnt=1,ans;
vector<int> g[105][105];
int dfs(ll x,ll col,ll cn){
	mark[col][x]=cn;
	f(i,0,g[col][x].size()){
		if(mark[col][g[col][x][i]]==0)
			dfs(g[col][x][i],col,cn);
	}
}
int main(){
	cin>>n>>m;
	f(i,0,m){
		Get(x,y);get(c);
		g[c][x].pb(y);
		g[c][y].pb(x);
	}
	f(i,1,m+1){
		cnt=1;
		f(j,1,n+1){
			if(mark[i][j]==0){
				dfs(j,i,cnt);
				cnt++;
			}
		}
	}
	cin>>q;
	f(i,0,q){
		Get(x,y);
		ans=0;
		f(j,1,m+1){
			if(mark[j][x]==mark[j][y])
				ans++;
		}
		cout<<ans<<endl;
	}
}