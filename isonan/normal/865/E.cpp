#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
//#define int long long

int get(char ch){
	if(ch>='0'&&ch<='9')return ch-'0';
	else return ch-'a'+10;
}
char str[15];
int num[15],now[15],sum[1048576];
long long Pow[15];
long long f[1048576];
signed main(){
	scanf("%s",str+1);
	int n=strlen(str+1);
	int Cnt=0;
	for(int i=1;i<=n;i++)num[n-i+1]=get(str[i]),Cnt+=num[n-i+1];
	Pow[1]=1;
	for(int i=2;i<=n;i++)Pow[i]=1ll*Pow[i-1]*16; 
//	for(int i=1;i<=n;i++)printf("%d ",num[i]);putchar('\n');
	long long ans=1e18;
	for(int i=0;i<(1<<(n-1));i++){
		bool cando=1;
		for(int j=1;j<=n;j++)now[j]=num[j];
		for(int j=1;j<n;j++)
			if(i&(1<<(j-1)))now[j]-=16,now[j+1]++;
		int cnt=0;
		for(int j=1;j<=n;j++)cnt+=now[j];
		if(cnt)continue;
		if(__builtin_popcount(i)!=(Cnt/15))continue;
//		for(int j=1;j<=n;j++)printf("%d ",now[j]);putchar('\n');
		for(int j=0;j<(1<<n);j++)f[j]=1e18;
		f[0]=0;
		sum[0]=0;
		for(int j=1;j<(1<<n);j++){
			for(int l=1;l<=n;l++)
				if(j&(1<<(l-1))){
					int &p=sum[j^(1<<(l-1))];
					sum[j]=p+now[l];
					if(p>=0&&p<16)
						f[j]=std::min(f[j],((1ll*sum[j^(1<<(l-1))])<<((l-1)*4))+f[j^(1<<(l-1))]);
				}
//			printf("%d %lld\n",j,f[j]);
		}
		ans=std::min(ans,f[(1<<n)-1]);
//		printf("%lld\n",ans);
	}
	if(ans==1e18){
		puts("NO");
		return 0;
	}
	for(int i=1;i<=n;i++)str[i]='0';
	int tem=n;
	while(ans){
		str[tem]=(ans%16<10)?ans%16+'0':(ans%16-10+'a');
		ans/=16;
		--tem;
	}
	for(int i=1;i<=n;i++)putchar(str[i]);
}