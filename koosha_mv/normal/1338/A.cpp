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

const int N=2e5+9;
int t,n,a[N],mn,ans;
int solve(int x){
	f(i,0,33)
		if((1ll<<i)>x) return i;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		f(i,0,n) gett(a[i]);
		mn=1e9;
		ans=0;
		f_(i,n-1,0){
			minm(mn,a[i]);
			if(i==0 || a[i]>a[i-1])
				maxm(ans,solve(a[i]-mn));
		}
		cout<<ans<<endl;
	}
}