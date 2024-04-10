#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

#define b(x) (1<<((x)-1))

int i,j,k,n,m,t;
ll a[200500],f[200500][3][2][2],res=-1e18;
#define mx(x,y) x=max(x,y)

int main() {
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n==1){cout<<a[1];return 0;}
	memset(f,-10,sizeof(f));
	f[1][1][1][0]=a[1];
	f[1][0][0][0]=-a[1];
	for(i=1;i<=n;i++){
		for(j=0;j<3;j++){
			mx(f[i+1][(j+1)%3][1][1],f[i][j][1][1]+a[i+1]);
			mx(f[i+1][(j+1)%3][1][1],f[i][j][1][0]+a[i+1]);
			mx(f[i+1][(j+1)%3][1][1],f[i][j][0][1]+a[i+1]);
			mx(f[i+1][(j+1)%3][1][0],f[i][j][0][0]+a[i+1]);
			
			mx(f[i+1][j][0][1],f[i][j][0][1]-a[i+1]);
			mx(f[i+1][j][0][1],f[i][j][0][0]-a[i+1]);
			mx(f[i+1][j][0][1],f[i][j][1][1]-a[i+1]);
			mx(f[i+1][j][0][0],f[i][j][1][0]-a[i+1]);
			if(i==n&&((j+n)%3)==2){
				res=max({res,f[i][j][0][1],f[i][j][1][1]});
			}
		}
	}
	cout<<res;
}