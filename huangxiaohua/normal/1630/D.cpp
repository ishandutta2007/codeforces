#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll a[1005000],res,ji,ou,x,y;

#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline ll read()
{
    char c=getchar();ll x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

void work(){
	ll tmp=0;
	for(i=1;i<=m;i++){
		k=n+1-i;
		ji=-1e18;ou=0;
		for(j=k-m;j>=1;j-=m){
			x=max(ji+a[j],ou-a[j]);
			y=max(ou+a[j],ji-a[j]);
			ji=x;ou=y;
		}
		tmp+=max(ji-a[k],ou+a[k]);
	}
	res=max(res,tmp);
}

int main(){
    ios::sync_with_stdio(0);
	t=read();
	while(t--){
		n=read();m=read();
		for(i=1;i<=n;i++){
			a[i]=read();
		}
		k=0;
		for(i=1;i<=m;i++){
			j=read();k=__gcd(j,k);
		}
		m=k;
		res=-1e18;
		work();
		for(i=1;i<=m;i++)a[n+1-i]*=-1;
		work();
		printf("%lld\n",res);
	}
}