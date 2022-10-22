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
const int N=1e5+9;
int s,n,a[N];
ll ans=1e13;
ll solve(int x){
	ll res=0,sum=0;
	f(i,0,n-1){
		sum+=a[i];
		res+=min(sum%x,x-(sum%x));
	}
	if(res==0)
		cout<<x<<" "<<s<<endl;
	return res;
}
int main(){
	cin>>n;
	f(i,0,n){
		gett(a[i]);
		s+=a[i];
	}
	if(s==1) return cout<<-1,0;
	minm(ans,solve(s));
	for(int i=2;i*i<=s;i++){
		if(s%i==0)
			minm(ans,min(solve(i),solve(s/i)));
	}
	cout<<ans;
}