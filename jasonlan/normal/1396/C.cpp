#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1001000;
ll ans; 
int n;
ll a[maxn],f[2][maxn],r1,r2,r3,d;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main()
{
	n=read();r1=read();r2=read();r3=read();d=read();
	for(register int i=1;i<=n;++i)
		a[i]=read();
	f[0][1]=min(r2,r1*(a[1]+1));
	f[1][1]=min(r1*a[1]+r3,f[0][1]+d*2+r1);
	for(register int i=2;i<=n;++i){
		f[0][i]=min(f[1][i-1]+d+min(r2,r1*(a[i]+1)),f[0][i-1]+d+min(r2,r1*(a[i]+1))+d+r1+d);
		f[1][i]=min(f[1][i-1]+d+r1*a[i]+r3,f[0][i-1]+d+min(r2,r1*(a[i]+1))+d+r1+d+r1);
		f[1][i]=min(f[1][i],f[0][i-1]+d+r1*a[i]+r3+d+r1+d);
	}
	printf("%lld\n",min(f[1][n],f[0][n-1]+d+r1*a[n]+r3+d+r1));
	return 0;
}