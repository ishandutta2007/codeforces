#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=201000;
int n,a[maxn];
long long ans;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main()
{
	int T=read();
	while(T--){
		n=read();a[0]=read();
		ans=0;
		for(register int i=1;i<n;++i){
			a[i]=read();
			ans+=max(0,a[i-1]-a[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}