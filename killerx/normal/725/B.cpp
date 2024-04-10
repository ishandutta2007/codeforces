#include<cstdio>
int main(){
	long long n;
	scanf("%lld",&n);
	char c=getchar();
	long long div4=n/4;
	if(n%4==0)--div4;
	long long ans=div4*16;
	if(!div4)ans=0;
	ans+=((n-1)%2)?7:0;
	ans+=c>='d'?'g'-c:c-'a'+4;
	printf("%lld\n",ans);
	return 0;
}