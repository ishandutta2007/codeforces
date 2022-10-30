#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll x[2050],y[2050],res,dx,dy,len,g;

map<tuple<ll,ll,ll>,ll>mp;

int main() {
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			len=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			dx=x[i]-x[j];
			dy=y[i]-y[j];
			g=__gcd(dx,dy);
			dx/=g;dy/=g;
			if(dx<0){dx=-dx;dy=-dy;}
			res+=mp[{dx,dy,len}];
			mp[{dx,dy,len}]++;
		}
	}
	printf("%lld",res/2);
}