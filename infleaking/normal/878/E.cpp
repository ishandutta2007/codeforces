#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pi;
const ll N=5e5+10,mo=1e9+7,v2=mo+1>>1;
ll a[N],n,t,q;
pi f[N],g[N];
ll pre[N][20],res[N][20];
ll sum[N],inv2[N];
ll div2(ll x){
	return (x-(x&1)>>1)+(x&1);
}
ll gsum(ll l,ll r){
	return (sum[r]-sum[l]+mo)*inv2[l]%mo;
}
int read(){
	ll w=0,z=1;char e=getchar();
	while (e!='-'&&!('0'<=e&&e<='9'))e=getchar();
	if (e=='-')z=-1,e=getchar();
	for (;'0'<=e&&e<='9';e=getchar())w=w*10+e-'0';
	return w*z;
} 
int main(){
	cin>>n>>q;
	ll pw2=1;
	inv2[0]=1;
	for (int i=1;i<=n;i++)a[i]=read(),sum[i]=(sum[i-1]+(a[i]*(pw2=pw2*2%mo)))%mo,inv2[i]=inv2[i-1]*v2%mo;
	for (int x=1;x<=n;x++){
		for (int i=1;i<=t;i++)
			if (div2(f[i].first)+a[x]<=0)pre[x][0]=f[i].second-1;
		if (a[x]<=0)pre[x][0]=x-1;
		int t1=0;
		for (int i=1;i<=t;i++){
			ll z=div2(f[i].first)+a[x];
			if (z>a[x])break;
			if (i==1||z!=f[t1].first)
				f[++t1]=make_pair(z,f[i].second);
			else f[t1].second=f[i].second;
		}
		if (f[t1].first<a[x]||!t1)f[++t1]=make_pair(a[x],x);
		else f[t1].second=x;
		t=t1;
	}
	for (int i=1;i<=n;i++){
		res[i][0]=gsum(pre[i][0],i);
		for (int j=1;j<20;j++)pre[i][j]=pre[pre[i][j-1]][j-1],res[i][j]=(res[pre[i][j-1]][j-1]+res[i][j-1])%mo;
	}
	while (q--){
		int l=read(),r=read();
		ll ans=0;
		for (int i=19;i>=0;i--)
			if (pre[r][i]>=l)
				ans=(ans+res[r][i])%mo,r=pre[r][i];
		ans=(ans+a[l]+gsum(l,r))%mo;
		printf("%I64d\n",(ans%mo+mo)%mo);
	}
}