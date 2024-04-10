#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e5+9;
int n;
ll s[M],a[M],b[M],d[M];
void work(){
	scanf("%d",&n);
	a[n+1]=0;
	for(int i=1;i<=n;++i){
		b[i]=0;
		scanf("%lld",&s[i]);
		a[i]=s[i];
	}
	for(int i=n;i>=1;--i)a[i]-=a[i+1];
	b[1]=a[1],b[2]=a[2];d[n]=a[n],d[n-1]=a[n-1];
	for(int i=3;i<=n;++i)b[i]=min(a[i],b[i-2]);
	for(int i=n-2;i>=1;--i)d[i]=min(a[i],d[i+2]);
	if(a[1]==0&&b[n]>=0&&b[n-1]>=0){
		printf("YES\n");
		return;
	}
	for(int i=2;i<=n;++i){
		ll x=2ll*(s[i]-s[i-1]);
		if(a[i]-s[i]+s[i-1]<0)continue;
		if(b[i-1]+x<0)continue;
		if(i>2&&b[i-2]-x<0)continue;
		if(i&1)x=-x;
		if(a[1]+x!=0)continue;
		if(i<n&&d[i+1]<0)continue;
		if(i+1<n&&d[i+2]<0)continue;
		printf("YES\n");
		return;
	}
	printf("NO\n");
}
int main(){
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;++i)work();
	return 0; 
}
/*
1
5
1 1 3 2 3
*/