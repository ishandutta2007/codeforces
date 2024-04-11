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
int n,t,m,c,ans[N],p,e,sum,b[N];
int main(){
	cin>>n>>m;
	f(i,0,m){cin>>b[i];sum+=b[i];}
	e=n-(b[m-1]+m-1);
	ans[m]=n+1;
	f_(i,m-1,0)
		ans[i]=min(ans[i+1]-1,n+1-b[i]);
	e=ans[0]-1;
	if(e<0) return cout<<-1,0;
	sum=0;
	ans[m]=n+1;
	f_(i,m-1,0){
		ans[i]-=sum;
		p=max(ans[i]-e,ans[i+1]-b[i]);
		e-=ans[i]-p;
		sum+=ans[i]-p;
		ans[i]=p;
	}
	if(ans[0]!=1) return cout<<-1,0;
	f(i,0,m) cout<<ans[i]<<" ";
}