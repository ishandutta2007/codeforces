#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1010;
int n,k;
ll mi[19];
double f[maxn][maxn];
inline ll read(){
	ll res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
ll query(ll x){
	if(!x)return 0;
	ll res=0;
	int len=0;
	while(len<=18&&mi[len]<=x)++len;
	--len;
	for(register int i=0;i<len;++i)
		res+=mi[i];
	if(x/mi[len]>1)res+=mi[len];
	else res+=x%mi[len]+1;
	return res;
}
int main(){
	n=read();
	mi[0]=1;
	for(register int i=1;i<=18;++i)
		mi[i]=mi[i-1]*10;
	f[0][0]=1;
	for(register int i=1;i<=n;++i){
		ll l=read(),r=read();
		double p=(double)(query(r)-query(l-1))/(r-l+1);
		for(register int j=1;j<=i;++j)
			f[i][j]=f[i-1][j-1]*p+f[i-1][j]*(1-p);
		f[i][0]=f[i-1][0]*(1-p);
	}
	k=read();
	double ans=0;
	for(register int i=ceil(1.0*k/100*n);i<=n;++i)
		ans+=f[n][i];
	printf("%.15lf",ans);
    return 0;
}