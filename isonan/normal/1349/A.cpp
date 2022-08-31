#include <cstdio>
#define int long long

int n,a[200001],cnt[200001],ans=1,tot;
int pri[200001];
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",a+i),++cnt[a[i]];
	for(int i=2;i<=200000;i++)
		if(!pri[i]){
			int mn=0x7f7f7f7,skdmn=0x7f7f7f7f;
				int tot=0;
			for(int j=i;j<=200000;j+=i){
				int cnt=0,tem=j;
				pri[j]=1;
				while(tem%i==0)++cnt,tem/=i;
				tot+=::cnt[j];
				if(::cnt[j]){
					if(mn>cnt)skdmn=mn,mn=cnt;
					else if(skdmn>cnt)skdmn=cnt;
				}if(::cnt[j]>1){
					if(mn>cnt)skdmn=mn,mn=cnt;
					else if(skdmn>cnt)skdmn=cnt;
				}
			}
			if(n-tot)skdmn=mn,mn=0;
			if(n-tot>1)skdmn=0;
//			printf("%d %d %d\n",mn,skdmn)
			for(int j=1;j<=skdmn;j++)ans*=i;
		}
	printf("%lld",ans);
}