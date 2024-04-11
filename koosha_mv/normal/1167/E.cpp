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

const int N=1e6+9;

ll n,t,mnnm=1e9,x,a[N],mn[N],mx[N],mxx[N],mnn[N],l,r,mid,c,cmx[N],mvx;
ll ans;

int main(){
	fill(mn,mn+N,1e9);
	cin>>n>>x;
	f(i,0,n){
		gett(a[i]);
		minm(mn[a[i]],i);
		maxm(mx[a[i]],i);
	}
	f(i,2,x+1){
		maxm(mvx,mx[i-1]);
		if(mn[i]<mvx){
			c=i;break;
		}
	}
	if(c==0)
		return cout<<1ll*x*(x+1)/2ll,0;
	f(i,1,x+1){
		cmx[i]=mx[i];
		maxm(mx[i],mx[i-1]);
	}
	f_(i,x,1){
		minm(mn[i],mn[i+1]);
	//	cout<<cmx[i]<<" "<<mn[i+1]<<endl;
		l=0,r=min(i,c);
		while(l+1<r){
			mid=(l+r)/2;
			if(mx[mid]<=mn[i+1]) l=mid;
			else r=mid;
		}
		ans+=l+1;
	//	ops(l);
		//cout<<cmx[i]<<" "<<mn[i+1]<<endl;
		if(!(cmx[i]<=mn[i+1])){
			break;
		}
	}
	cout<<ans;
	
}