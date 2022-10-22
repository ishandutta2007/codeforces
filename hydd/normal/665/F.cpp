#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,l,g[2100000];
int tot,p[2100000]; bool vis[2100000];
int cnt,pos1[2100000],pos2[2100000]; ll num[2100000];
void Sieve(int n){
	vis[1]=1;
	for (int i=2;i<=n;i++){
		if (!vis[i]) p[++tot]=i;
		for (int j=1;j<=tot&&i*p[j]<=n;j++){
			vis[i*p[j]]=true;
			if (!(i%p[j])) break;
		}
	}
}
int calc(ll x){ return x<=l?pos1[x]:pos2[n/x];}
void upd(ll x){
	num[++cnt]=x; g[cnt]=x-1;
	if (x<=l) pos1[x]=cnt;
	else pos2[n/x]=cnt;
}
int main(){
	scanf("%lld",&n); l=1;
	while (l*l<=n) l++;
	l--; Sieve(l);
	for (ll i=1,j;i<=n;i=j+1){
		j=n/(n/i); upd(n/i);
	}
	for (int j=1;j<=tot;j++)
		for (int i=1;1ll*p[j]*p[j]<=num[i];i++)
			g[i]-=(g[calc(num[i]/p[j])]-(j-1));
	int pos=1; ll ans=0;
	for (int j=1;j<=tot;j++){
		if (1ll*p[j]*p[j]*p[j]<=n) ans++;
		while (num[pos]>n/p[j]) pos++;
		ans+=g[pos]-j;
	}
	printf("%lld\n",ans);
	return 0;
}