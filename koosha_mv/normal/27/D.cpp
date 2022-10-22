#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=105;
ll n,m,edge[N][2],ans[N],mark[N];
vector<int> g[N];
bool inser(int s1,int s2,int s3,int s4){
	if(s2<s1) swap(s1,s2);
	return (((s3<s2 && s3>s1)+(s4<s2 && s4>s1)==1)&&(s1!=s3)&&(s1!=s4)&&(s2!=s3)&&(s2!=s4));
}
void dfs(int x,int col){
	mark[x]=1,ans[x]=col;
	f(i,0,g[x].size()){
		if(mark[g[x][i]]==1 && ans[g[x][i]]==ans[x]){cout<<"Impossible";exit(0); }
		if(mark[g[x][i]]==0) dfs(g[x][i],!col);
	}
}
int main(){
	cin>>n>>m;
	f(i,0,m){
		Get(edge[i][0],edge[i][1]);
		f(j,0,i){
			if(inser(edge[i][0],edge[i][1],edge[j][0],edge[j][1]))
				g[i].pb(j),g[j].pb(i);
		}
	}
	f(i,0,m){
		if(!mark[i]) dfs(i,0);
	}
	f(i,0,m){
		if(ans[i]==1) cout<<'o';
		else cout<<'i';
	}
}