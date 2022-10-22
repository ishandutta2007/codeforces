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
const int N=1e5+9;
ll n,a[N],t,k=1,d=0,mark[N],mn=1e9,an,b[2],ans[N],mark1[N],cnt;
vector<int> g[N];
void dfs(int x){
	mark[x]=1,t++;
	f(i,0,g[x].size()){
		if(mark[g[x][i]]==0) dfs(g[x][i]);
	}
}
void dfs1(int x){
	mark1[x]=1;
	ans[cnt++]=x;
	f(i,0,g[x].size()){
		if(mark1[g[x][i]]==0)
			dfs1(g[x][i]);
	}
}
int main(){
	cin>>n;
	f(i,1,n+1){
		get(a[i]);
		g[i].pb(a[i]);
	}
	f(i,1,n+1){
		if(mark[i]==0){
			t=0;
			dfs(i);
			k=(k && (t%2==0));
			if(t<mn){
				mn=t;
				an=i;
				b[0]=i;
				b[1]=a[i];
			}
		}
	}
	if(mn>2 || (mn==2 && k==0)){cout<<"NO";return 0;}
	cout<<"YES"<<endl;
	if(b[0]!=b[1]) cout<<b[0]<<" "<<b[1]<<endl;
	f(i,1,n+1){
		if(mark1[i]==0 && i!=b[0] && i!=b[1])
			dfs1(i);
	}
	f(i,0,cnt) cout<<b[i%2]<<" "<<ans[i]<<endl;
}