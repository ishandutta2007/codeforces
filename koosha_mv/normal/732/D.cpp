#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=1e5+9;

ll t,n,m,a[N],e[N],mid,l,r=N,mark[N],t1;
bool check(ll x){
	f(i,0,N) mark[i]=0;
	t=0;
	f_(i,x,1){
		if(mark[e[i]]==0 && e[i]!=0)
			mark[e[i]]=i,t++;
	}
	t1=0;
	f(i,1,x+1){
		if(mark[e[i]]==i)
			t1-=a[e[i]];
		else
			t1++;
		if(t!=m || t1<0) return 0;
	}
	return 1;
}
int main(){
	cin>>n>>m;
	f(i,1,n+1) get(e[i]);
	f(i,1,m+1) get(a[i]);
	r=n+1;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else l=mid;
	}
	cout<<r-((n+2)*(r>n));
}