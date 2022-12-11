#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int f[110000];
int n,p[110000],a[110000],pd[110000];
long long ans[110000],w[110000],num;
int findfather(int k1){
	if (f[k1]==k1) return k1; return f[k1]=findfather(f[k1]);
}
int merge(int k1,int k2){
	if (pd[k1]==0||pd[k2]==0) return 0;
	k1=findfather(k1); k2=findfather(k2);
	f[k1]=k2; w[k2]+=w[k1]; num=max(num,w[k2]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]); w[i]=a[i];
	}
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	num=0;
	for (int i=n;i;i--){
		int k1=p[i]; num=max(num,1ll*a[k1]);
		pd[k1]=1;
		merge(k1,k1+1);
		merge(k1,k1-1);
		ans[i-1]=num;
	}
	for (int i=1;i<=n;i++) printf("%I64d\n",ans[i]);
	return 0;
}