#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,t,a[N],b[N];

int main(){
	cin>>t;
	while(t--){
		int mn1=1e9,mn2=1e9;
		ll ans=0;
		cin>>n;
		f(i,0,n){ cin>>a[i]; minm(mn1,a[i]); }
		f(i,0,n){ cin>>b[i]; minm(mn2,b[i]); }
		f(i,0,n)
			ans+=max(a[i]-mn1,b[i]-mn2);
		cout<<ans<<endl;
	}
}