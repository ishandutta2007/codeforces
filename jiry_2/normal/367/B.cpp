#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
map<int,unsigned long long>num;
long long hash[200010],a[200010],b[200010];
long long x[200010],mo=1000000007,y[200010];
long long quick(long long k1,long long k2){
	if (k2==1) return k1;
	long long k3=quick(k1,k2/2);
	if (k2%2==0) return k3*k3%mo; else return k3*k3%mo*k1%mo;
}
int main(){
	long long n,m,p; srand(1235);
	num.clear();
	scanf("%I64d%I64d%I64d",&n,&m,&p);
	for (long long i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (long long i=1;i<=m;i++) scanf("%I64d",&b[i]);
	for (int i=1;i<=n;i++) {if (num[a[i]]==0) num[a[i]]=(((1ll*rand())<<32)+rand())%mo; a[i]=quick(num[a[i]],1232);}
	for (int i=1;i<=m;i++) {if (num[b[i]]==0) num[b[i]]=(((1ll*rand())<<32)+rand())%mo; b[i]=quick(num[b[i]],1232);}
	memset(hash,0x00,sizeof hash);
	memset(x,0x00,sizeof x);
	memset(y,0x00,sizeof y);
	for (long long i=1;i<=p;i++){
		if (i+(m-1)*p>n) break;
		for (long long j=0;j<m;j++) hash[i+(m-1)*p]=(hash[i+(m-1)*p]+a[i+j*p])%mo;
		for (long long j=i+m*p;j<=n;j+=p) hash[j]=((hash[j-p]-a[j-m*p]+a[j])%mo+mo)%mo;
	}
	long long key=0;
	for (long long i=1;i<=m;i++) key=(key+b[i])%mo; 
	int ans=0;
	for (long long i=1+(m-1)*p;i<=n;i++) if (hash[i]==key) ans++;
	cout<<ans<<endl;
	for (long long i=1+(m-1)*p;i<=n;i++) if (hash[i]==key) printf("%I64d ",i-(m-1)*p);
	cout<<endl; return 0;
}