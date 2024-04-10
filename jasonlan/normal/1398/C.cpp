#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=101000;
int n,a[maxn];
long long ans;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
inline int readch(){
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	return ch-'0';
}
int main(){
	int T=read();
	while(T--){
		n=read();
		a[0]=ans=0;
		for(register int i=1;i<=n;++i)
			a[i]=a[i-1]+readch()-1;
		sort(a,a+n+1);
		a[n+1]=-maxn;
		for(register int i=0,j=0;i<=n;i=j){
			while(a[i]==a[j])++j;
			ans+=((long long)(j-i)*(j-i-1))>>1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}