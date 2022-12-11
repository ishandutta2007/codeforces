#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=501000,mod=998244353;
int n,k,m,ans=1;
int l[maxn],r[maxn],x[maxn];
int a[maxn],pos[maxn],f[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int qmod(int x){return x>=mod?x-mod:x;}
int main(){
	n=read();k=read();m=read();
	for(register int i=0;i<m;++i)
		l[i]=read(),r[i]=read(),x[i]=read();
	for(register int p=0;p<k;++p){
		for(register int i=1;i<=n+1;++i)
			a[i]=f[i]=pos[i]=0;
		for(register int i=0;i<m;++i){
			if((x[i]>>p)&1)a[l[i]]++,a[r[i]+1]--;
			else pos[r[i]+1]=max(pos[r[i]+1],l[i]);
		}
		for(register int i=1;i<=n+1;++i)
			a[i]+=a[i-1],pos[i]=max(pos[i],pos[i-1]);
		f[0]=1;
		for(register int i=1,sum=1,l=0;i<=n+1;++i){
			while(l<pos[i])sum=qmod(sum-f[l]+mod),++l;
			f[i]=a[i]?0:sum;
			sum=qmod(sum+f[i]);
		}
		ans=1ll*ans*f[n+1]%mod;
	}
	printf("%d\n",ans);
	return 0;
}