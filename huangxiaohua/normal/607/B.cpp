#include<bits/stdc++.h>
using namespace std;

#define M 19650827

int i,j,k,n,a[505],l,r;
int f[505][505];

int main(){
	memset(f,0x3f,sizeof(f));
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[i][i]=1;
	}
	for(i=2;i<=n;i++){
		for(j=1;j+i-1<=n;j++){
			l=j;r=j+i-1;
			if(i==2&&a[l]==a[r]){f[l][r]=1;continue;}
			if(a[l]==a[r]){f[l][r]=f[l+1][r-1];}
			for(k=l+1;k<=r;k++){
				f[l][r]=min(f[l][r],f[l][k-1]+f[k][r]);
			}
		}
	}
	printf("%d",f[1][n]);
}