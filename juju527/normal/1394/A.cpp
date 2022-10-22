#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int a[maxn];
ll sum[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
	int n,d,m;
	n=read();d=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
	int num=n;
	for(int i=1;i<=n;i++)if(a[i]>m){num=i-1;break;}
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	ll res=0;
	for(int i=1;i<=n-num;i++){
		if(1ll*(i-1)*(d+1)+1>n)break;
		if(1ll*i*d<n-num-i)continue;
		res=max(res,sum[n]-sum[n-i]+sum[num]-sum[max(1ll*(i-1)*d-n+num+i,0ll)]);
	}
	if(n-num==0)res=sum[n];
	printf("%lld\n",res);
	return 0;
}