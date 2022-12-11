#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1000100;
int n,q,sz;
int opt[maxn<<1];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
bool check(int p){
	int cnt=0;
	for(register int i=1;i<=q;++i)
		cnt+=opt[i]>0?(opt[i]<=p):-(-opt[i]<=cnt);
	return cnt;
}
int main()
{
	n=read();q=read();
	for(register int i=1;i<=n;++i)
		opt[i]=read();
	for(register int i=1;i<=q;++i){
		opt[n+i]=read();
	}
	q+=n;
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d",!check(l)?0:l);
	return 0;
}