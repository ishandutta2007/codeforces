#include <bits/stdc++.h>
using namespace std;
int T,n,m,p,k;
char s[1000010];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1),n=strlen(s+1);
		int tmp=0,tmp2=0;
		long long ans=0;
		for(int i=1,now=0;i<=n;i++){
			if(s[i]=='-') now--;
			if(s[i]=='+') now++;
			tmp=min(tmp,now);
		}
		for(int i=1,now=0;i<=n;i++){
			if(s[i]=='-') now--;
			if(s[i]=='+') now++;
			if(now<tmp2) ans++;
			tmp2=min(tmp2,now);
			ans+=(tmp2-tmp+1);
		}
		printf("%lld\n",ans);
	}
}