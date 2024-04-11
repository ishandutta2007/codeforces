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
const int N=3e5+20,mod= 998244353;
ll t,n,k,a[N],ans,b[N],cnt;
int main(){
	cin>>n>>k;
	f(i,0,n){ get(a[i]);}
	f_(i,n,n-k+1) ans+=i;
	cout<<ans<<endl;
	ans=1;
	f(i,0,n)
		if(a[i]>n-k)
			b[cnt++]=i;
	f(i,0,cnt-1)
		ans=(ans*(b[i+1]-b[i]))%mod;
	cout<<ans;
}