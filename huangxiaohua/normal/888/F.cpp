#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
int i,j,k,n,m,t,a[505][505],l,r;
ll f[505][505],f2[505][505];

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		f[i][i]=f2[i][i]=1;
		for(j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<n;i++){
		if(a[i][i+1]){f[i][i+1]=f2[i][i+1]=1;}
	}
	for(i=3;i<=n;i++){
		for(j=1;j+i-1<=n;j++){
			l=j;r=j+i-1;
			if(a[l][r]){
				for(k=l;k<r;k++){
					f2[l][r]+=f[l][k]*f[k+1][r]%M;
				}
				f2[l][r]%=M;
			}
			
			f[l][r]=f2[l][r];
			for(k=l+1;k<r;k++){
				f[l][r]+=f2[l][k]*f[k][r]%M;
			}
			f[l][r]%=M;
		}
	}
	printf("%lld",f[1][n]);
}