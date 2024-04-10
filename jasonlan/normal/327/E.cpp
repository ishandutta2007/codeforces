#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=24,mod=1e9+7;
int n;
int k,b[maxn];
int f[1<<maxn];
long long sum[1<<maxn];
int qmod(int x){
	return x>=mod?x-mod:x;
}
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
bool check(int p){
	sum[p]=sum[p&-p]+sum[p^(p&-p)];
	return sum[p]==b[0]||sum[p]==b[1];
}
void update(int p){
	for(register int i=p,j;i;i^=j)
		j=i&-i,f[p]=qmod(f[p]+f[p^j]);
}
int main(){
	n=read();
	for(register int i=0;i<n;++i)sum[1<<i]=read();
	k=read();
	for(register int i=0;i<k;++i)b[i]=read();
	f[0]=1;
	for(register int i=1;i<1<<n;++i){
		if(check(i))continue;
		update(i);
	}
	printf("%d",f[(1<<n)-1]);
	return 0;
}