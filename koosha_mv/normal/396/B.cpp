#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops cout<<"!"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

int t,n,k,g;
ll ans1,ans2,p,q,p2,r,l;
bool prime(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 1;
	return 0;
}
int main(){
	cin>>t;
	for(;t;t--){
		gett(n);
		l=n,r=n+1;
		for(;prime(l);l--){}
		for(;prime(r);r++){}
		g=__gcd(ans1=(l-2)*r+(n-l+1)*2,ans2=l*r*2);
		printf("%lld/%lld\n",ans1/g,ans2/g);
	}
}