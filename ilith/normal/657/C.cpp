#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(rgi i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
const int N=400010;
ll n,k,b,c,a[N],inf=2e9+10,ans=1e17,su;
priority_queue<ll>s;
ll calc(ll x,ll y){
	assert(x<=y);
	ll d=y-x;
	return min(d*c,d/5*b+d%5*c);
} 
signed main(){
	scanf("%lld%lld%lld%lld",&n,&k,&b,&c);
	FOR(i,1,n)scanf("%lld",a+i),a[i]+=1000000000;
	sort(a+1,a+n+1);
	FOR(g,0,4){
		ll st=inf+g;
		while(!s.empty())s.pop();
		su=0;
		FOR(i,1,n){
			ll t=(a[i]/5*5)+g;
			while(t<a[i])t+=5;
			ll co=calc(t,st);
			ll h=calc(a[i],st);
			s.push(h),su+=h;
			while(s.size()>k)su-=s.top(),s.pop();
			if(s.size()==k)ans=min(ans,su-co*k);
		}
	}
	printf("%lld",ans);
	return 0;
}