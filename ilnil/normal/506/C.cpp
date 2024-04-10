#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define ll long long
using namespace std;
const int N=1e5+5;
int n,m,k,p,h[N],a[N],nd[N];
ll ans,b[N];
bool ck(ll mi){
	ll s=0;
	fo(i,1,n)b[i]=(ll)a[i]*m+h[i],(b[i]>mi?s+=(b[i]-mi+p-1)/p:0);
	if(s>m*k)return 0;
	fo(i,0,m)nd[i]=0;
	fo(i,1,n)if(b[i]>mi)
		for(ll j=(b[i]-mi-1)%p+1;j<=b[i]-mi;j+=p)
			++nd[max((j-h[i]+a[i]-1)/a[i],0LL)];
	int cut=0;
	fo(i,0,m-1)cut+=nd[i],cut=max(0,cut-k);
	return !(cut+nd[m]);
}
int main(){
	cin>>n>>m>>k>>p;
	fo(i,1,n)scanf("%d%d",&h[i],&a[i]);
	for(ll l=0,r=1e13,mi;mi=l+r>>1,l<=r;)
		if(ck(mi))r=mi-1,ans=mi;else l=mi+1;
	cout<<ans;
}