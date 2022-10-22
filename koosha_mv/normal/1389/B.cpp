#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl
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

int n,k,z,t,ans,a[N];

int calc(int x){
	int res=0,y=k-x*2,mx=0;
	if(x*2>k) return 0;
	f(i,0,y+1) res+=a[i];
	f(i,0,y+1) maxm(mx,a[i]+a[i+1]);
	return res+mx*x;
}

int main(){
	cin>>t;
	while(t--){
		ans=0;
		cin>>n>>k>>z;
		f(i,0,n) gett(a[i]);
		f(i,0,z+1)
			maxm(ans,calc(i));
		cout<<ans<<'\n';
	}
}