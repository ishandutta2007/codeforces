#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[210000],K,n,len,pd[210000];
long long prew[210000],inf=1e16;
void insert(int where,int k1){
	while (k1){
		a[where]+=k1%10; len=max(len,where); k1/=10;
		if (a[where]>10) k1++,a[where]-=10; where++;
	}
}
int main(){
	scanf("%d%d",&n,&K);
	for (int i=0;i<=n;i++) scanf("%d",&a[i]);
	prew[n]=0;
	for (int i=n-1;i>=0;i--) prew[i]=max(-inf,min(inf,prew[i+1]*2+a[i+1]*2));
	//for (int i=0;i<=n;i++) cout<<prew[i]<<" "; cout<<endl;
	long long now=0; int ans=0;
	for (int i=0;i<=n;i++){
		if (-prew[i]-now>=-K&&-prew[i]-now<=K&&(i!=n||prew[i]+now!=0)) ans++;
		now+=a[i]; if (now%2!=0) break; now/=2;
	}
	printf("%d\n",ans);
	return 0;
}