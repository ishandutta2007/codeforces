#include <bits/stdc++.h>
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

const int N=1e6+99;

int n,t,ck,mark[N];
ll sum,h[N],ans[N];

ll find(ll x){
	ll l=0,r=1e9,mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(mid*(mid+1)/2<=x) l=mid;
		else r=mid;
	}
	return l;
}

main(){
	cin>>n;
	f(i,0,n){
		get(h[i])
		sum+=h[i];
	}
	ll mid;
	mid=(sum-1ll*n*(n-1)/2)/n;
	if(mid*n+1ll*n*(n-1)/2<sum) mid++;
	sum-=mid*n;
	f_(i,n-1,0){
		ll u=find(sum);
		ans[i]=mid+u;
		sum-=u;		
	}
	f(i,0,n) cout<<ans[i]<<" ";
	cout<<'\n';
}