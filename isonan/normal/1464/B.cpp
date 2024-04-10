#include <cstdio>
#include <cstring>
#include <algorithm>

char str[100001];
int x,y;
int main(){
	scanf("%s",str+1);
	scanf("%d%d",&x,&y);
	int n=strlen(str+1),cnt1=0,cnt2=0,cnt3=0;
	if(x>y){
		std::swap(x,y);
		for(int i=1;i<=n;i++){
			if(str[i]=='0')str[i]='1';
			else if(str[i]=='1')str[i]='0';
		}
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(str[i]=='0'){
			sum+=1ll*y*cnt2;
			++cnt1;
		}
		else if(str[i]=='1'){
			sum+=1ll*x*cnt1;
			++cnt2;
		}
		else ++cnt3;
	}
	int sum0=cnt1,sum1=cnt2,sum2=cnt3;
	cnt1=cnt2=cnt3=0;
	long long ans=0,fin=1e18;
	for(int i=1;i<=n;i++){
		if(str[i]=='?')ans+=1ll*x*cnt1+1ll*y*(sum0-cnt1);
		if(str[i]=='0')++cnt1;
		else ++cnt2;
	}
	fin=ans;
	cnt1=cnt2=0;
	for(int i=1;i<=n;i++){
		if(str[i]=='0')++cnt1;
		else if(str[i]=='1')++cnt2;
		if(str[i]=='?'){
			++cnt3;
			ans-=1ll*x*cnt1+1ll*y*(sum0-cnt1);
			ans+=1ll*x*(sum1-cnt2)+1ll*y*cnt2;
			fin=std::min(fin,ans+1ll*cnt3*(sum2-cnt3)*x);
		}
	}
//	for(int i=1;i<=n;i++){
//		if(str[i]=='0')++cnt1;
//		if(str[i]=='1')++cnt2;
//		if(str[i]=='?')++cnt3;
//	}
//	long long ans=1e18;
//	for(int i=0;i<=cnt3;i++)ans=std::min(ans,1ll*(cnt1+i)*(cnt2+cnt3-i));
//	printf("%lld\n",ans);
	printf("%lld\n",fin+sum);
}