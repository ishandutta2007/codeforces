#include <cstdio>
const int Maxn=100000;
char s[Maxn+5];
int sum[Maxn+5];
int n,x;
int main(){
	int t;
	scanf("%d",&t);
	int ans;
	while(t--){
		scanf("%d%d",&n,&x);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				sum[i]=sum[i-1]+1;
			}
			else{
				sum[i]=sum[i-1]-1;
			}
		}
		ans=0;
		if(x==0){
			ans++;
		}
		if(sum[n]==0){
			if(x==0){
				puts("-1");
				continue;
			}
			for(int i=1;i<=n;i++){
				if(sum[i]==x){
					ans=-1;
					break;
				}
			}
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++){
			if(1ll*(x-sum[i])*sum[n]>=0&&(x-sum[i])%sum[n]==0){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}