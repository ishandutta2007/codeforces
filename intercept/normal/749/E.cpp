#include<bits/stdc++.h>
#define ll long long
#define pii pair<long long,int>
using namespace std;
const int M=1e5+9;
int n;
ll a[M];
int b[M],p[M],d[M];
long double ans=0;
void add(int i){for(int v=i;i<=n;i+=i&-i)a[i]+=v,b[i]++;}
pii sum(int i,ll x=0,int y=0){for(;i;i-=i&-i)x+=a[i],y+=b[i];return pii(x,y);}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&p[i]);
		d[p[i]]=i;
	}
	for(int i=n;i>=1;--i){
		add(d[i]);
		pii o=sum(d[i]-1);
		ans+=(long double)o.second-(long double)2.0*((n-d[i]+1)/(1.0*n)*o.first)/(1.0*(n+1));
	}
	for(int i=2;i<=n;++i)ans+=(long double)i/(1.0*n)*(i-1)/(2.0*(n+1))*(n-i+1);
	printf("%.10Lf\n",ans);
	return 0;
}