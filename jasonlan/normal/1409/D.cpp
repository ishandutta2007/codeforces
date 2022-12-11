#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef long long ll;
ll n,ans,dmax;
int s;
inline ll read(){
	ll res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main()
{
	for(register int T=read();T;--T){
		n=read();s=read();
		dmax=1;
		while(dmax<n)dmax*=10;
		if(dmax==n){
			puts("0");continue;
		}
		ans=dmax-n;
		while(n){
			dmax/=10; 
			s-=n/dmax;
			n%=dmax;
			if(!s&&!n){
				ans=0;break;
			}
			else if(s<=0)break;
			ans=dmax-n;
		}
		if(s>0)puts("0");
		else printf("%lld\n",ans);
	}
	return 0;
}