#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#define mid ((l+r)>>1)
using namespace std;
const int maxn=100010;
int n,m;
int a[maxn],pre[maxn],bac[maxn];
int f[maxn],ft;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	n=read();m=read();
	for(register int i=1;i<=n;++i){
		a[read()]++;a[read()+1]--;
	}
	for(register int i=1;i<=m;++i)
		a[i]+=a[i-1];
	for(register int i=1,x;i<=m;++i){
		if(a[i]>=f[ft]){
			pre[i]=ft+1;
			f[++ft]=a[i];
		}
		else{
			x=upper_bound(f,f+ft,a[i])-f;
			pre[i]=x;
			if(x)f[x]=a[i];
		}
	}
	ft=0;
	for(register int i=m,x;i;--i){
		if(a[i]>=f[ft]){
			bac[i]=ft+1;
			f[++ft]=a[i];
		}
		else{
			x=upper_bound(f,f+ft,a[i])-f;
			bac[i]=x;
			if(x)f[x]=a[i];
		}
	}
	int ans=0;
	for(register int i=1;i<=m;++i)
		ans=max(ans,pre[i]+bac[i]-1);
	printf("%d",ans); 
    return 0;
}