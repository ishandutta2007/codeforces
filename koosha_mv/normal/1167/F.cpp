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
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const ll N=1e6+9,mod=1e9+7;

ll n,tree[2][N*2];
pair<ll,ll> a[N];
ll p,ans;

ll query(int l, int r,int source) {
	ll res=0;
	r++;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
   	if (l&1) res+=tree[source][l++],res%=mod;
   	if (r&1) res+=tree[source][--r],res%=mod;
	}
  return res%mod;
}
void add_tree(int x,ll y){
	x+=n;
	while(x)
		tree[0][x]+=y,tree[1][x]++,x/=2;
}

main(){
	cin>>n;
	f(i,0,n){
		get(a[i].F);
		a[i].S=i;
	}
	sort(a,a+n);
	f(i,0,n){
		p=query(0,a[i].S,0);
		ans=(ans+p*(n-a[i].S)%mod*a[i].F%mod)%mod;
		p=query(a[i].S,n-1,0);
		p=query(a[i].S,n-1,1)*(n+1)-p;
		ans=(ans+p*(a[i].S+1)%mod*a[i].F%mod)%mod;
		ans=(ans+1ll*(a[i].S+1)*(n-a[i].S)%mod*a[i].F%mod)%mod;
		add_tree(a[i].S,a[i].S+1);
	}
	cout<<ans;
}