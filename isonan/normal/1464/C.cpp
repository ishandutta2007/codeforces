#include <cstdio>

int n,cnt[101];
long long T;
char s[100001];
int main(){
	scanf("%d%lld%s",&n,&T,s+1);
	T-=(1ll<<(s[n]-'a'))-(1ll<<(s[n-1]-'a'));
	for(int i=1;i<=n-2;i++){
		++cnt[s[i]-'a'];
		T+=(1ll<<(s[i]-'a'));
	}
	if(T<0||(T&1)){
		puts("No");
		return 0;
	}
	T>>=1;
	for(int i=60;~i;--i){
		long long sum=0;
		bool good=0;
		for(int j=i;~j;--j){
			sum+=1ll*cnt[j]*(1ll<<j);
			if(sum>=((T>>i)<<i)){
				cnt[j]=(sum-((T>>i)<<i))>>j;
				T&=(1ll<<i)-1;
				good=1;
				break;
			}
			else cnt[j]=0;
		}
		if(!good){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}