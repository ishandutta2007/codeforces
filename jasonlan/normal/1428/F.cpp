#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=550100;
long long ans,pval;
int n,cnt;
int f[maxn];
char c[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	n=read();
	scanf("%s",c+1);
	for(register int i=1;i<=n;++i){
		if(!(c[i]-'0')){
			while(cnt){
				f[cnt]=i-cnt;
				pval+=1ll*(f[cnt]-f[cnt+1])*cnt;
				--cnt;
			}
			ans+=pval;
		}
		else{
			++cnt;
			pval-=1ll*(f[cnt]-f[cnt+1])*cnt;
			ans+=1ll*cnt*(cnt-1)/2+1ll*(i-cnt-f[cnt+1]+1)*cnt+pval;
		}
	}
	printf("%lld",ans);
	return 0;
}