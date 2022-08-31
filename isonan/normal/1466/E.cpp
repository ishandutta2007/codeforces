#include <cstdio>

int t,n,cnt[61],Pow[61];
long long x[500001];
const int P=1000000007;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		for(int i=0;i<60;i++)cnt[i]=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",x+i);
			for(int j=0;j<60;j++)
				if(x[i]&(1ll<<(1ll*j)))++cnt[j];
		}
		for(int i=0;i<60;i++)Pow[i]=(1ll<<i)%P;
		long long tot=0;
		for(int i=1;i<=n;i++){
			long long ans1=0,ans2=0;
			for(int j=0;j<60;j++){
				if(x[i]&(1ll<<(1ll*j)))
					ans1+=1ll*Pow[j]*cnt[j]%P; 
			}
			for(int j=0;j<60;j++){
				if(x[i]&(1ll<<(1ll*j)))
					ans2+=1ll*n*Pow[j]%P;
				else ans2+=1ll*Pow[j]*cnt[j]%P;
			}
			ans1%=P;
			ans2%=P;
			tot+=1ll*ans1*ans2%P;
//			printf("%d %d\n",ans1,ans2);
		}
		printf("%d\n",tot%P);
	}
}