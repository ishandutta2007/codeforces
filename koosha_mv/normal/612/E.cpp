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
const int N=1e6+3;
ll n,p[N],ans[N],mark[N];
vector<vector<int> > g[N];
vector<int> v;
void dfs(int x){
	v.pb(x);
	mark[x]=1;
	if(mark[p[x]]==0) dfs(p[x]);
}
void solve(vector<int> v){
	int s=v.size()/2;
	f(i,0,v.size()){
		if(i<=s)
			ans[v[i]]=v[(i+s+1)%v.size()];
		else
			ans[v[i]]=v[i-s];
	}
}
int main(){
	cin>>n;
	f(i,1,n+1) get(p[i]);
	f(i,1,n+1){
		v.clear();
		if(mark[i]==0){
			dfs(i);
		}
		g[v.size()].pb(v);
	}
	f(i,1,n+1){
		if(i%2==0 && g[i].size()%2==1){cout<<-1;return 0;}
		if(i%2==0 && 1){
			f(j,0,g[i].size()){
				f(k,0,g[i][j].size()){
					int b=j-(j%2==1)+(j%2==0);
					ans[g[i][j][k]]=g[i][b][(k+(j%2))%i];
				}
			}
		}
		else{
			f(j,0,g[i].size())
				solve(g[i][j]);
			
		}
	}
	f(i,1,n+1) cout<<ans[i]<<" ";
}