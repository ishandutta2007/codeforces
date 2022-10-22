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
const int N=3e5+99;
int n,t,a[N],b[N],ans,m,k;
int main(){
	cin>>n>>m>>k;
	f(i,0,n){
		gett(a[i]);
		
	}
	sort(a,a+n);
	f(i,0,n-1)
		b[i]=a[i+1]-a[i]-1;
	sort(b,b+n-1);
	ans=n;
	f(i,0,n-k){

		ans+=b[i];
	}
	cout<<ans;
}