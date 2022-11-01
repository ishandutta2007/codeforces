#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int mo=1e9+7;
int n,ans,k,_n[100],xs[100];
int ksm(int x,int y){
	int t=1;
	for(;y;y>>=1,x=(ll)x*x%mo)if(y&1)t=(ll)t*x%mo;
	return t;
}
void get(){
	_n[0]=n;
	fo(i,1,k)_n[i]=_n[i-1]/xs[i];
	fo(i,0,k)_n[i]-=_n[i+1];
	int sum=0,tot=1;
	fo(i,0,k){
		sum+=_n[i];
		tot=(ll)tot*_n[i]%mo*ksm(sum,mo-2)%mo;
	}
	ans=(ans+tot)%mo;
}
int main(){
//	freopen("a.in","r",stdin);
	cin>>n;
	for(;(1LL<<k+1)<=n;)++k;
	fo(i,1,k)xs[i]=2;
	get();
	if((1LL<<k-1)*3<=n){
		fo(i,1,k){
			fo(j,1,k)xs[j]=2;
			xs[i]=3;
			get();
		}
	}
	fo(i,1,n)ans=(ll)ans*i%mo;
	printf("%d\n",ans);
}