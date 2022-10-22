#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=2e5+9;
int n,t,mark[N],tl=0,m[N],p[N],c[N],ans,sz[N],e[N][170],szg[N],a[N],t2[N];
void dfs(int x,int dist){
	tl++;
	a[dist]=c[x];
	mark[x]=1;
	if(mark[p[x]]==0)
		dfs(p[x],dist+1);
}
bool check(int y){
	f(j,0,y) m[j]=0,t2[j]=0;
	f(i,1,tl+1){
		if(m[i%y]!=a[i]) t2[i%y]++;
		m[i%y]=a[i];
	}
	f(j,0,y)
		if(t2[j]==1) return 1;
	return 0;
}
void solve(int x){
	tl=0;
	dfs(x,1);
	for(int j=0;j<sz[tl] && e[tl][j]<ans;j++){
		if(check(e[tl][j]))
			ans=e[tl][j];
	}
}
int main(){
	gett(t);
	f(i,1,N){
		for(int j=i;j<N;j+=i)
			e[j][sz[j]++]=i;
	}
	while(t--){
		ans=1e9;
		gett(n);
		f(i,1,n+1){get(p[i]);mark[i]=0;}
		f(i,1,n+1) get(c[i]);
		f(i,1,n+1){
			if(mark[i]==0){
				solve(i);
			}
		}
		printf("%d\n",ans);
	}
}