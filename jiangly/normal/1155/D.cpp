#include<bits/stdc++.h>
typedef long long ll;
const int N=3e5+5;
template<class T>T max(const T&a,const T&b){
	return a>b?a:b;
}
template<class T>T min(const T&a,const T&b){
	return a<b?a:b;
}
int n,x;
int a[N];
ll sum_1[N],sum_2[N],f_1[N],f_2[N],g_1[N],g_2[N];
ll ans;
int main(){
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i){
		sum_1[i]=sum_1[i-1]+a[i];
	}
	for(int i=1;i<=n;++i){
		g_1[i]=min(g_1[i-1],sum_1[i]);
	}
	for(int i=1;i<=n;++i){
		g_1[i]+=(x-1)*sum_1[i];
		g_1[i]=min(g_1[i],g_1[i-1]);
	}
	for(int i=1;i<=n;++i){
		f_1[i]=sum_1[i]*x-g_1[i];
	}
	for(int i=n;i;--i){
		sum_2[i]=sum_2[i+1]+a[i];
	}
	for(int i=n;i;--i){
		g_2[i]=min(g_2[i+1],sum_2[i]);
	}
	for(int i=n;i;--i){
		g_2[i]+=(x-1)*sum_2[i];
		g_2[i]=min(g_2[i],g_2[i+1]);
	}
	for(int i=n;i;--i){
		f_2[i]=sum_2[i]*x-g_2[i];
	}
	for(int i=0;i<=n;++i){
		ans=max(ans,f_1[i]+f_2[i+1]);
	}
	printf("%I64d\n",ans);
	return 0;
}