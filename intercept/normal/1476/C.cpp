#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e5+9;
int n;
int a[M],b[M],c[M];
ll f[M];
void work(){
	ll ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		scanf("%d",&b[i]);
		if(a[i]>b[i])swap(a[i],b[i]); 
	}
	for(int i=1;i< n;++i){
		if(a[i+1]==b[i+1])f[i]=1;
		else {
			f[i]=1ll*b[i+1]-a[i+1]+1;
			if(f[i-1])f[i]=max(f[i],f[i-1]+a[i+1]+c[i]-b[i+1]+1);
		}
		ans=max(ans,f[i]+c[i+1]);
	}
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
2
5 6
-1 1
-1 2
*/