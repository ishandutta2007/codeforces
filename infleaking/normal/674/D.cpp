#include<cstdio>
#include<iostream>
#include<cstring>
#include<set>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll b[N],e[N],cnt[N];
ll n,q,a[N],d[N];
multiset<ll> s[N],f;
void backward(ll x,int sig){
	if (d[a[x]]>2)f.erase(f.find(e[a[x]]+*s[a[x]].begin()));
	if (d[a[x]]>2)f.erase(f.find(e[a[x]]+*s[a[x]].rbegin()));
	if (sig)s[a[x]].erase(s[a[x]].find(cnt[x]+e[x]+b[x]%d[x]));
}
void recov(ll x,int sig){
	if (sig)s[a[x]].insert(cnt[x]+e[x]+b[x]%d[x]);
	if (d[a[x]]>2)f.insert(e[a[x]]+*s[a[x]].begin());
	if (d[a[x]]>2)f.insert(e[a[x]]+*s[a[x]].rbegin());
}
int main(){
	cin>>n>>q;
	for (ll i=1;i<=n;i++)scanf("%I64d",&b[i]);
	for (ll i=1;i<=n;i++)scanf("%I64d",&a[i]),d[a[i]]++,d[i]+=2;
	for (ll i=1;i<=n;i++){
		e[i]=b[i]/d[i];
		cnt[a[i]]+=e[i];
	}
	for (ll i=1;i<=n;i++)s[a[i]].insert(cnt[i]+e[i]+b[i]%d[i]);
	for (ll i=1;i<=n;i++){
		if (d[i]>2){
			f.insert(e[i]+*s[i].begin());
			f.insert(e[i]+*s[i].rbegin());
		}
	}
	while (q--){
		ll ty,x,y;
		scanf("%I64d",&ty);
		if (ty==3)printf("%I64d %I64d\n",*f.begin(),*f.rbegin());
		if (ty==2)scanf("%I64d",&x),printf("%I64d\n",cnt[x]+e[x]+b[x]%d[x]+e[a[x]]);
		if (ty==1){
			scanf("%I64d%I64d",&x,&y);
			backward(a[a[x]],1);
			backward(a[x],1);
			backward(x,1);
			d[a[x]]--;
			cnt[a[x]]-=e[x];
			cnt[a[a[x]]]-=e[a[x]];
			e[a[x]]=b[a[x]]/d[a[x]];
			cnt[a[a[x]]]+=e[a[x]];
			recov(x,0);
			recov(a[x],1);
			recov(a[a[x]],1);
			
			a[x]=y;
			
			backward(a[a[x]],1);
			backward(a[x],1);
			backward(x,0);
			d[a[x]]++;
			cnt[a[x]]+=e[x];
			cnt[a[a[x]]]-=e[a[x]];
			e[a[x]]=b[a[x]]/d[a[x]];
			cnt[a[a[x]]]+=e[a[x]];
			recov(x,1);
			recov(a[x],1);
			recov(a[a[x]],1);
		}
	}
}