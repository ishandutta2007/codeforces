#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,m,t;
ll res=1e9,x,y,sb,a[200500];
ll f(ll x,ll y){ll z=x/y;return z*z*(y-(x-y*z))+(z+1)*(z+1)*(x-y*z);}
bool chk(ll t){
	ll su=0,tot=0,tmp=0;
	int l,r,md,ans,ans2,y=0;
	for(i=1;i<=n;i++){
		x=a[i]-a[i-1];
		l=2;r=x;ans=1;
		while(l<=r){
			md=(l+r)/2;
			if(f(x,md-1)-f(x,md)>t)ans=max(ans,md),l=md+1;else r=md-1;
		}
		su+=f(x,ans);tot+=ans;
		l=2;r=x;ans2=1;
		while(l<=r){
			md=(l+r)/2;
			if(f(x,md-1)-f(x,md)>=t)ans2=max(ans2,md),l=md+1;else r=md-1;
		}
		tmp+=ans2-ans;
	}
	if(su-tmp*t<=sb){
		res=min(res,tot+max(0ll,(su-sb+t-1)/t));
		return 0;
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	cin>>sb;
	ll l=0,r=1e18,md;
	while(l<=r){
		md=(l+r)/2;
		if(chk(md))r=md-1;else l=md+1;
	}
	cout<<res-n;
}