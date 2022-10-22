#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
#define LL long long
using namespace std;
const int N=3e5+10;
int n;
LL a[N],b[N],sum[N],f[N][2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%I64d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%I64d",&b[i]);
	for(int i=n;i>=1;--i){
		sum[i]=sum[i+1]+a[i]+b[i];
		f[i][0]=f[i+1][0]+sum[i+1]+b[i]*(LL)((n-i)*2+1);
		f[i][1]=f[i+1][1]+sum[i+1]+a[i]*(LL)((n-i)*2+1);
		//cout<<f[i][0]<<" "<<f[i][1]<<endl;
	}
	LL x=0,y=0,ans=0;
	for(int i=1;i<=n;++i){
		if(i&1){
			ans=max(ans,x+f[i][0]+sum[i]*y);
			x+=y*a[i];
			++y;
			x+=y*b[i];
			++y;
		}
		else{
			ans=max(ans,x+f[i][1]+sum[i]*y);
			x+=y*b[i];
			++y;
			x+=y*a[i];
			++y;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}