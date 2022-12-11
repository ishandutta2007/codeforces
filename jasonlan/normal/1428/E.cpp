#include<iostream>
#include<cstdio>
#include<queue>
#define mp make_pair
using namespace std;
typedef long long ll;
int n,k;
ll ans;
priority_queue <pair<ll,pair<ll,int> > > q;
inline ll read(){
	ll res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
ll calc(ll x,int y){
	return (x/y)*(x/y)*(y-x%y)+(x/y+1)*(x/y+1)*(x%y);
}
int main(){
	n=read();k=read()-n;
	for(register int i=1,x;i<=n;++i){
		x=read();
		ans+=calc(x,1);
		q.push(mp(calc(x,1)-calc(x,2),mp(x,2)));
	}
	while(k--){
		ans-=q.top().first;
		ll x=q.top().second.first,p=q.top().second.second;
		q.pop();
		if(x==p)continue;
		q.push(mp(calc(x,p)-calc(x,p+1),mp(x,p+1)));
	}
	printf("%lld",ans);
	return 0;
}