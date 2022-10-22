#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const ll inf=1e18;
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
priority_queue<pll> q;
int main(){
    int n;
	n=read();
	q.push(pll(read()-1,0));
	for(int i=1;i<n;i++){
		ll a,v=-inf;
		a=read();
		while(q.size()){
			ll t=q.top().fi,b=q.top().se;
			if(t<a)break;
			q.pop();
			b+=(t-(t%a))*i;
			q.push(pll(t%a,b));
			v=max(v,b-a*i);
		}
		if(v!=-inf)q.push(pll(a-1,v));
	}
	ll res=-inf;
	while(q.size()){
		ll t=q.top().fi,b=q.top().se;
		q.pop();
		res=max(res,t*n+b);
	}
	printf("%lld\n",res);
    return 0;
}