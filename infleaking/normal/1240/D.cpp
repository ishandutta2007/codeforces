#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
using namespace std;
typedef long long ll;
const ll N=3e5+10,mo=23333333333333333,step=2e7+3;
map<ll,int> p;
int d[N],t,a[N];
ll mul(ll a,ll b){
	ll c=(long double)a*b/mo,z=a*b-c*mo;
	if (z<0)z+=mo;
	return z>=mo?z-mo:z;
}
int n,T;
ll pw[N];
int main(){
	pw[0]=1;
	for (int i=1;i<=300000;i++)pw[i]=mul(pw[i-1],step);
	for (cin>>T;T--;){
		scanf("%d",&n);
		p.clear();
		ll now=0,ans=0;
		p[0]=1;
		for (int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if (d[t]==x)now=(now-mul(d[t],pw[t])+mo)%mo,t--;
			else d[++t]=x,now=(now+mul(d[t],pw[t])+mo)%mo;
			ans+=p[now]++;
		}
		printf("%lld\n",ans);
	}
}