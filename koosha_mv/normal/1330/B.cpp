#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=3e5+9;
int n,t,mn1[N],mn[N],mx[N],mx1[N],cnt,ans[N],mark[N],g[N],g1[N],a[N];
int main(){
	cin>>t;
	f(q,0,t){
		cnt=0;
		cin>>n;
		f(i,0,n+2) mx[i]=0,mn1[i]=0,mark[i]=0,mark[i+1]=0;
		f(i,0,n+2) mn[i]=0,mn1[i]=0,g[i]=g1[i]=0;
		f(i,0,n){
			gett(a[i]);
			if(mark[a[i]]!=0) g[i]=-1;
			mark[a[i]]=1;
		}
		f(i,1,n+1) mark[i]=0;
		f_(i,n-1,0){
			if(mark[a[i]]!=0) g1[i]=-1;
			mark[a[i]]=1;
		}
		f(i,1,n) if(g[i]!=-1){ g[i]=g[i-1];}
		f_(i,n-2,0) if(g1[i]!=-1) g1[i]=g1[i+1];
		mx[0]=mn[0]=a[0];
		f(i,1,n) mx[i]=max(a[i],mx[i-1]),mn[i]=min(a[i],mn[i-1]);
		mx1[n-1]=mn1[n-1]=a[n-1];
		f_(i,n-2,0) mx1[i]=max(mx1[i+1],a[i]),mn1[i]=min(mn1[i+1],a[i]);
		f(i,0,n-1){
			if(mn[i]==1 && mx[i]==i+1 && g[i]==0 && g1[i+1]==0 && mn1[i+1]==1 && mx1[i+1]==n-i-1) ans[cnt++]=i+1;
		}
		cout<<cnt<<endl;
		f(i,0,cnt) cout<<ans[i]<<" "<<n-ans[i]<<endl;
	}
}