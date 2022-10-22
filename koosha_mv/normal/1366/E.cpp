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
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99,mod=998244353;

int n,m,t,l=1,r,a[N],b[N];
ll ans=1;

int main(){
	cin>>n>>m;
	if(m>n) return cout<<0,0;
	f(i,0,n) gett(a[i]);
	f(i,0,m) gett(b[i]);
	f_(i,n-2,0)
		minm(a[i],a[i+1]);
	if(a[0]!=b[0]) return cout<<0,0;
	f(i,1,m){
		while(l+1<n && a[l]<b[i])
			l++;
		if(a[l]!=b[i]) return cout<<0,0;
		r=l;
		while(r<n && a[r]==b[i]) r++;
		ans=ans*(r-l)%mod;
	}
	cout<<ans;
}