#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=3e5+5,mo=998244353;
int n,sum;
ll a[N],f[N],g[N];
ll k1[N],k2[N],b[N],tot;
int ksm(int x,int y){
	int t=1;
	for(;y;y>>=1,x=(ll)x*x%mo)if(y&1)t=(ll)t*x%mo;
	return t;
}
int main(){
//	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin>>n;
	fo(i,1,n)cin>>a[i],sum+=a[i];
	int iv=ksm(sum,mo-2),iv1=ksm(n-1,mo-2);
	fo(i,0,sum-1){
		k1[i]=(ll)(sum-i)*iv%mo*iv1%mo;
		k2[i]=(ll)i*iv%mo;
		b[i]=1;
		int a=ksm(k1[i]+k2[i],mo-2);
		k1[i]=k1[i]*a%mo;
		k2[i]=k2[i]*a%mo;
		b[i]=b[i]*a%mo;
	}
	fo(i,1,sum-1){
		b[i]=(b[i]+k2[i]*b[i-1])%mo;
		int v=k2[i]*k1[i-1]%mo;
		v=ksm(1-v,mo-2);
		b[i]=(ll)b[i]*v%mo;
		k1[i]=(ll)k1[i]*v%mo;
//		k1[i]=(k1[i]+k2[i]*k1[i-1])%mo;
	}
	fd(i,0,sum-1)g[i]=(g[i+1]*k1[i]+b[i])%mo;
//	printf("%lld\n",(g[0]+mo)%mo);
	fo(i,1,n)tot=(tot+g[a[i]])%mo;
	ll ans=0;
	ans=(tot-(n-1)*g[0])%mo*ksm(n,mo-2)%mo;
	printf("%lld\n",(ans+mo)%mo);
}