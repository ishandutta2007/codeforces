#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int i,j,k,n,m,x,y;
ll r1,r2,r3,d,a[1005000],f1[1005000][2],f2[1005000],res=1e18;

int main(){
	scanf("%d%lld%lld%lld%lld",&n,&r1,&r2,&r3,&d);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		f2[i]=f1[i][0]=f1[i][1]=1e18;
	}
	f2[n]=min({r1*(a[n]+2)+2*d,r2+r1+2*d,r1*a[n]+r3});
	f2[n-1]=min({r1*(a[n]+2)+4*d,r2+r1+4*d,r1*a[n]+r3+2*d})+min({r1*a[n-1]+r1*2,r1+r2,r1*a[n-1]+r3});
	for(i=n-2;i>=1;i--){
		f2[i]=f2[i+1]+2*d+min({r1*(a[i]+2),r1+r2,r1*a[i]+r3});
	}
	f1[1][0]=f1[1][1]=min({r1*a[1]+r1*2+2*d,r1+r2+2*d,r1*a[1]+r3});
	for(i=2;i<=n;i++){
		f1[i][0]=min(f1[i][0],f1[i-1][0]+d+r1*a[i]+r3);
		f1[i][0]=min(f1[i][0],f1[i-1][1]+d+r1*a[i]+r3);
		f1[i][0]=min(f1[i][0],f1[i-1][0]+3*d+r1*a[i]+r1*2);
		f1[i][0]=min(f1[i][0],f1[i-1][0]+3*d+r1+r2);
		f1[i][0]=min(f1[i][0],f1[i-1][1]+3*d+r1*a[i]+r1*2);
		f1[i][0]=min(f1[i][0],f1[i-1][1]+3*d+r1+r2);
		f1[i][1]=min({f1[i-2][0],f1[i-2][1]})+4*d-d*(i==2)+min({r1*a[i-1]+r1*2,r1+r2,r1*a[i-1]+r3})+min({r1*a[i]+r1*2,r1+r2,r1*a[i]+r3});
		f1[i][1]=min(f1[i][1],f1[i-1][1]+3*d+min({r1*(a[i]+2),r1+r2,r1*a[i]+r3}));
	}
	for(i=1;i<=n+1;i++){
		res=min(res,d+min(f1[i-1][0],f1[i-1][1])+f2[i]);
	}
	res=min({res,f2[1],f1[n][1],f1[n][0]});
	printf("%lld",res);
}