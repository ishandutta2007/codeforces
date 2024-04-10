#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int inf=1e9;
const int N=1e6+10;
const LL P=998244353; 

int n;
int a[N];
LL jc[N],ny[N];
int main(){
	jc[0]=jc[1]=1;ny[0]=ny[1]=1;
	for(LL i=2;i<=1000000;++i){
		jc[i]=jc[i-1]*i%P;
		ny[i]=(P-P/i)*ny[P%i]%P;
	}
	for(LL i=2;i<=1000000;++i) ny[i]=ny[i-1]*ny[i]%P;
	scanf("%d",&n);
	for(int i=1;i<=n*2;++i) scanf("%d",&a[i]);
	sort(a+1,a+1+n+n);
	LL ans=0;
	for(int i=1;i<=n;++i) ans=ans-(LL)a[i];
	for(int i=n+1;i<=n+n;++i) ans=ans+(LL)a[i];
	ans=ans%P;
	ans=ans*jc[n+n]%P*ny[n]%P*ny[n]%P;
	ans=(ans%P+P)%P;
	cout<<ans<<endl;
	return 0;
}