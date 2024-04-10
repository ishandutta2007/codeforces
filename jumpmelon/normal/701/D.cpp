#include<bits/stdc++.h>
#define ll long long
#define inf 0x7f7f7f7f
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int n,K;
double l,v1,v2;
double ans;
int main()
{
	n=read();
	scanf("%lf%lf%lf",&l,&v1,&v2); K=read();
	int k=n/K+(n%K!=0);
	if(n<=K) printf("%.10lf",l/v2);
	else 
	{
	    double p=(double)(1LL*(2*k-1)*l*v2+1LL*l*v1)/(2LL*k*v1*v2);
	    double p1=1-(v1-v2)/(2*k*v1);
	    ans=p/p1;
	    printf("%.10lf",ans);
	}
	return 0;
}