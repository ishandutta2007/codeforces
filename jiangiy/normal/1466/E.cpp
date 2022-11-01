#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int P=1000000007;
int n;
LL a[60],po[60],s[500005];
int main(){
	po[0]=1;
	for(int i=1;i<=59;i++)po[i]=po[i-1]*2%P;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld",s+i);
		memset(a,0,sizeof(a));
		LL ans=0;
		for(int i=1;i<=n;i++) for(int j=0;j<60;j++)a[j]+=s[i]>>j&1;
		for(int i=1;i<=n;i++){
			LL x=0,y=0;
			for(int j=0;j<60;j++){
				if(s[i]>>j&1){
					x=(x+a[j]*po[j])%P;
					y=(y+n*po[j])%P;
				}
				else{
					y=(y+a[j]*po[j])%P;
				}
			}
			ans=(ans+x*y)%P;
		}
		printf("%lld\n",ans);
	}
}