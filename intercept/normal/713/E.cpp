#include<bits/stdc++.h>
using namespace std;
const int M=2e5+9;
int n,m,p=1;
int a[M],b[M],f[M];
bool check(int x){
	for(int i=2;i<=n;++i){
		f[i]=f[i-1];
		if(f[i-1]>=b[i]-1)f[i]=b[i]+x;
		if(f[i-1]>=b[i]-x-1)f[i]=max(f[i],b[i]);
		if(i>2&&b[i]-x-1<=f[i-2])f[i]=max(f[i],b[i-1]+x);
	}
	if(f[n]>=m-x-1)return 1;
	f[2]=x;
	for(int i=3;i<=n;++i){
		f[i]=f[i-1];
		if(f[i-1]>=b[i]-1)f[i]=b[i]+x;
		if(f[i-1]>=b[i]-x-1)f[i]=max(f[i],b[i]);
		if(i>2&&b[i]-x-1<=f[i-2])f[i]=max(f[i],b[i-1]+x);
	}
	return f[n]>=m+b[2]-x-1;
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		a[i+n]=a[i]+m;
	}
	for(int i=1;i<=n;++i){
		if(a[i+1]-a[i]>a[p+1]-a[p])p=i;
	}
	int l=0,r=a[p+1]-a[p];
	for(int i=1;i<=n;++i)b[i]=a[p+i]-a[p+1];
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}