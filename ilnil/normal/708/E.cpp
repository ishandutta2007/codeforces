#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int N=1505,M=1e5+5,mo=1e9+7;
int n,m,a,b,k,g[N],_g[N];
int pre[N],suf[N],all,can;
int pre2[N],suf2[N],su;
int jc[M],ny[M],_[M],_2[M];
int ksm(int x,int y){
	int t=1;
	for(;y;y>>=1,x=(ll)x*x%mo)if(y&1)t=(ll)t*x%mo;
	return t;
}
int main(){
	cin>>n>>m>>a>>b>>k;
	a=(ll)ksm(b,mo-2)*a%mo;
	jc[0]=_[0]=_2[0]=1;
	fo(i,1,k)jc[i]=(ll)jc[i-1]*i%mo,_[i]=(ll)_[i-1]*a%mo,_2[i]=(ll)_2[i-1]*(1-a)%mo;
	ny[k]=ksm(jc[k],mo-2);
	fd(i,0,k-1)ny[i]=(ll)ny[i+1]*(i+1)%mo;
	fo(i,0,min(m,k))g[i]=(ll)jc[k]*ny[i]%mo*ny[k-i]%mo*_[i]%mo*_2[k-i]%mo;
	_g[0]=g[0];
	fo(i,1,m)_g[i]=(_g[i-1]+g[i])%mo;
	fo(i,1,m)pre[i]=((ll)g[m-i]*_g[i-1]+pre[i-1])%mo;
	fd(i,1,m)suf[i]=((ll)g[i-1]*_g[m-i]+suf[i+1])%mo;
	fo(o,2,n){
		su=0;
		fd(i,1,m){
			su=(-(ll)g[m-i]*suf[i+1]+su)%mo;
			suf2[i]=((ll)(suf[1]-pre[i-1])*g[i-1]%mo*_g[m-i]+(ll)g[i-1]*su+suf2[i+1])%mo;
		}
		su=0;
		fo(i,1,m){
			su=(-(ll)g[i-1]*pre[i-1]+su)%mo;
			pre2[i]=((ll)(suf[1]-suf[i+1])*g[m-i]%mo*_g[i-1]+(ll)g[m-i]*su+pre2[i-1])%mo;
		}
		fo(i,1,m)pre[i]=pre2[i],suf[i]=suf2[i];
	}
	cout<<(pre[m]+mo)%mo;
}