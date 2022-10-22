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

int n,t,m,d,w,k;
ll ans,e,mv;

void solve(){
	cin>>m>>d>>w;
	k=min(m,d);
	if((d-1)%w==0){ cout<<1ll*k*(k-1)/2<<endl; return ; }
	mv=w/__gcd(d-1,w);
	ans=1ll*mv*(k/mv)*(k/mv-1)/2;
	e=k%mv;

	ans+=1ll*e*(k/mv);
	cout<<ans<<'\n';
}

int main(){
	cin>>t;
	while(t--)
		solve();
}