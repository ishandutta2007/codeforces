#include<bits/stdc++.h>
const int MAXN=100000;
int n;
int a[MAXN+5];
int pre_max[MAXN+5],suf_max[MAXN+5],pre_min[MAXN+5],suf_min[MAXN+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	pre_max[1]=1;
	pre_min[1]=1;
	for(int i=2;i<=n;++i){
		pre_max[i]=a[i]>a[pre_max[i-1]]?i:pre_max[i-1];
		pre_min[i]=a[i]<a[pre_min[i-1]]?i:pre_min[i-1];
	}
	suf_max[n]=n;
	suf_min[n]=n;
	for(int i=n-1;i>=1;--i){
		suf_max[i]=a[i]>a[suf_max[i+1]]?i:suf_max[i+1];
		suf_min[i]=a[i]<a[suf_min[i+1]]?i:suf_min[i+1];
	}
	for(int i=2;i<=n-1;++i){
		if(a[pre_min[i-1]]<a[i]&&a[i]>a[suf_min[i+1]]){
			puts("3");
			printf("%d %d %d\n",pre_min[i-1],i,suf_min[i+1]);
			return 0;
		}
		if(a[pre_max[i-1]]>a[i]&&a[i]<a[suf_max[i+1]]){
			puts("3");
			printf("%d %d %d\n",pre_max[i-1],i,suf_max[i+1]);
			return 0;
		}
	}
	puts("0");
	return 0;
}