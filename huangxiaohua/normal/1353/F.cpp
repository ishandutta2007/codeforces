#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll l,r,res,f[105][105],a[105][105];

ll get(ll x){
	memset(f,0x1f,sizeof(f));
	int i,j;ll k;
	f[0][1]=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			k=a[i][j]-(i+j-2+x);
			if(k<0){continue;}
			f[i][j]=min(f[i-1][j],f[i][j-1])+k;
		}
	}
	
	return min(f[n][m],f[0][0]);
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		res=1e18;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				scanf("%lld",&a[i][j]);
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				res=min(res,get(a[i][j]-i-j+2));
			}
		}
		printf("%lld\n",res);
	}
}