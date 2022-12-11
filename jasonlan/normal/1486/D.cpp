#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=201000;
int n,k;
int a[maxn],sum[maxn],mni[maxn];
bool check(int x){
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+(a[i]>=x ? 1 : -1);
		mni[i]=min(mni[i-1],sum[i]);
		if(i>=k&&sum[i]-mni[i-k]>=1)return true;
	}
	return false;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(!check(mid))r=mid-1;
		else l=mid;
	}
	printf("%d\n",l);
	return 0;
}