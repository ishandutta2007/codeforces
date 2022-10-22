#include<bits/stdc++.h>
#define upd(x) ans=max(ans,x)
using namespace std;
typedef long long ll;
ll n,l,r,k;
int main(){
	cin>>n>>l>>r>>k;
	ll ans=-1,a,b,s,t,len=(r-l+n)%n+1;
	if (n<=1e7){
		for (ll i=0;i<=n;i++){
			a=(k-len)%(n+i); b=i-a;
			if (0<=a&&a<=len&&0<=b&&b<=n-len) upd(i);

			a=(k-len+1)%(n+i); b=i-a;
			if (1<=a&&a<=len&&0<=b&&b<=n-len) upd(i);
		}
	} else{
		if (0<=k-len&&k-len<=len) upd(k-len+n-len);
		if (1<=k-len+1&&k-len+1<=len) upd(k-len+1+n-len);
		for (ll x=1;x<=10000;x++){
			//x(a+b)+a=k-len-xn
			s=k-len-x*n;
			a=s%x; b=(s-(x+1)*a)/x;
			if (x*(a+b)+a!=s) continue;
			if (a>len||b<0) continue;
			if (b<=n-len){ upd(a+b); continue;}
			t=(b-(n-len)-1)/(x+1)+1;
			a+=x*t; b-=(x+1)*t;
			if (0<=a&&a<=len&&0<=b&&b<=n-len) upd(a+b);
		}
		for (ll x=1;x<=10000;x++){
			//x(a+b)+a=k-len-xn+1(a>=1)
			s=k-len-x*n+1;
			a=s%x; b=(s-(x+1)*a)/x;
			if (a==0) a+=x,b-=(x+1);
			if (x*(a+b)+a!=s) continue;
			if (a>len||b<0) continue;
			if (b<=n-len){ upd(a+b); continue;}
			t=(b-(n-len)-1)/(x+1)+1;
			a+=x*t; b-=(x+1)*t;
			if (0<=a&&a<=len&&0<=b&&b<=n-len) upd(a+b);
		}
	}
	printf("%lld\n",ans);
	return 0;
}