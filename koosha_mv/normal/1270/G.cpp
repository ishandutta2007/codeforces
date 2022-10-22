#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=1e6+2;
int t,n,adj[N],ans[N],cnt,x,a[N],mark[N],u;
int main(){
	cin>>t;
	while(t--){
		gett(n);
		f_(i,n,1){
			gett(x);
			adj[i]=i+x;
		}
		f(i,1,n+1) mark[i]=0;
		u=1,cnt=1;
		while(!mark[u]){
			mark[u]=cnt;
			ans[cnt++]=u;
			u=adj[u];
		}
		printf("%d\n",cnt-mark[u]);
		f_(i,cnt-1,mark[u])
			cout<<n-ans[i]+1<<" ";
		printf("\n");
	}
}