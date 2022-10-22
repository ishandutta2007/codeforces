#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
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
#define int ll

const int N=2e5+99;

ll x,mx;
int n,a[N];

ll C(int x){
	return 1ll*x*(x+1ll)/2ll;
}
ll C(int x,int y){
	return C(y)-C(x);
}
void solve(){
	ll ans=C(a[0]),res;
	int p2=0,sum=a[0],e;
	f(p1,0,n){
		while(sum<x)
			p2=(p2+1)%n,sum+=a[p2],ans+=C(a[p2]);
		e=min(sum-x,a[p1]-1ll);
		res=ans-C(e)-C(a[p2]-(sum-x)+e,a[p2]);
		sum-=a[p1];
		ans-=(C(a[p1]));
		maxm(mx,res);
	}
}
main(){
	cin>>n>>x;
	f(i,0,n) gett(a[i]);
	solve();
	cout<<mx;
}