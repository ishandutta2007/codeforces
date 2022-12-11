#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k;
int f[210][20100];
int main(){
	scanf("%d%d",&n,&k);
	memset(f,-1,sizeof(f));
	f[0][0]=0;
	long long x;
	int pres=0;
	int cnt2,cnt5;
	for(int i=0;i<n;++i)
	{
		scanf("%lld",&x);
		cnt2=cnt5=0;
		while(x%2==0&&x)
		{
			++cnt2;x/=2;
		}
		while(x%5==0&&x){
			++cnt5;x/=5;
		}
		pres+=cnt5;
		for(register int j=min(i,k-1);j;--j)
			for(register int s=pres;s>=0;--s)
				if(f[j][s]!=-1)
					f[j+1][s+cnt5]=max(f[j+1][s+cnt5],f[j][s]+cnt2);
		f[1][cnt5]=max(f[1][cnt5],cnt2);
	}
	int ans=0;
	for(register int s=pres;s;--s)
		ans=max(ans,min(s,f[k][s]));
	printf("%d",ans);
	return 0;
}