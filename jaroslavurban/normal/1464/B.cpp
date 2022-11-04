#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100100;
ll cnt1[N],cnt0[N],cntq[N];
ll zerosleft[N],onesleft[N];
ll n,x,y;
string s;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>s>>x>>y;n=s.size();
	for(int i=1;i<=n;++i)cnt1[i]=cnt1[i-1]+(s[i-1]=='1');
	for(int i=1;i<=n;++i)cnt0[i]=cnt0[i-1]+(s[i-1]=='0');
	for(int i=1;i<=n;++i)cntq[i]=cntq[i-1]+(s[i-1]=='?');
	ll res=0;
	for(int i=0;i<n;++i){
		if(s[i]=='0')res+=cnt1[i]*y;
		if(s[i]=='1')res+=cnt0[i]*x;
	}
	for(int i=1;i<=n;++i){
		if(s[i-1]=='?')zerosleft[i]=cnt1[i]*y+(cnt1[n]-cnt1[i])*x;
		zerosleft[i]+=zerosleft[i-1];
	}
	for(int i=1;i<=n;++i){
		if(s[i-1]=='?')onesleft[i]=cnt0[i]*x+(cnt0[n]-cnt0[i])*y;
		onesleft[i]+=onesleft[i-1];
	}
	ll rs=1e18;
	for(int i=1;i<=n;++i){
		rs=min({rs,zerosleft[i]+onesleft[n]-onesleft[i]+cntq[i]*(cntq[n]-cntq[i])*x,onesleft[i]+zerosleft[n]-zerosleft[i]+cntq[i]*(cntq[n]-cntq[i])*y});
	}
	cout<<res+rs<<endl;
}