#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll a[N],h[N],n,m,k,p,ans;
struct ax{int i;ll h,a,c;};
bool operator < (ax a,ax b){
	return (a.c)>(b.c);
}
priority_queue<ax> s;
int check(ll lim){
	while (!s.empty())s.pop();
	for (int i=1;i<=n;i++)s.push((ax){i,lim,a[i],lim/a[i]});
	ll tag=0;
	for (int i=1;i<=m;i++){
		if (s.top().c<i)return 0;
		for (int j=1;j<=k;j++){
			ax z=s.top();
			if (z.c>=m){
				tag=k-j+1+(m-i)*k;
				break;
			}
			s.pop();
			z.h+=p;
			z.c=z.h/z.a;
			s.push(z);
		}
		if (tag)break;
	}
	while (!s.empty()){
		ax x=s.top();
		if (x.h-x.a*m<h[x.i])
			tag-=(h[x.i]-(x.h-x.a*m)+p-1)/p;
		s.pop();
	}
	return tag>=0;
}
int main(){
	cin>>n>>m>>k>>p;
	for (int i=1;i<=n;i++)scanf("%lld%lld",&h[i],&a[i]);
	for (ll u=1LL<<60;u;u>>=1)
		if (!check(ans+u))ans+=u;
	cout<<ans+1<<endl;
}