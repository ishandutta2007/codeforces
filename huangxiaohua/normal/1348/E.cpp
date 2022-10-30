#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,i,j,k,f[505][505],yes[505],a[505],b[505];
ll x,y,res;

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		x+=a[i];y+=b[i];
	}
	res=x/m+y/m;
	if((x%m+y%m)<m){printf("%lld",res);return 0;}
	x%=m;y%=m;
	f[0][x]=1;
	for(i=0;i<m;i++){
		int t1,t2;
		t1=i;t2=(x+y-i+m+m)%m;
		if((t1%m+t2%m)<m){yes[i]=1;}
	}
	for(i=1;i<=n;i++){
		for(j=0;j<m;j++){
			f[i][j]=f[i-1][j];
		}
		for(j=1;j<m;j++){
			if(a[i]<m-j||b[i]<j){continue;}
			for(k=0;k<m;k++){
				f[i][(j+k)%m]|=f[i-1][k];
			}
		}
	}
	for(i=0;i<m;i++){
		if(yes[i]&&f[n][i]){res++;break;}
	}
	printf("%lld",res);
}