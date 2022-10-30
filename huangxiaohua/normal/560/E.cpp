#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,m,t,fa[2050];
ll jc[300500],inv[300500];
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
struct sb{
	int x,y;ll w;
	bool operator<(const sb a)const{
		return (x==a.x)?y<a.y:x<a.x;
	}
}s[2050];
vector<int> v;

int main() {
	jc[0]=inv[0]=1;
	for(i=1;i<=300000;i++){jc[i]=jc[i-1]*i%M;}
	inv[300000]=ksm(jc[300000],M-2);
	for(i=299999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	scanf("%d%d%d",&s[0].x,&s[0].y,&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&s[i].x,&s[i].y);
	}
	for(i=0;i<=n;i++){
		s[i].w=c(s[i].x+s[i].y-2,s[i].x-1);
	}
	sort(s,s+n+1);
	for(i=0;i<=n;i++){
		for(j=i+1;j<=n;j++){
			s[j].w=(s[j].w-s[i].w*c(s[j].x-s[i].x+s[j].y-s[i].y,s[j].x-s[i].x)%M+M)%M;
		}
	}
	printf("%lld",s[n].w);
}