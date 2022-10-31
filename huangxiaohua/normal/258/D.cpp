#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,x,y,a[1050];
double res,f[1050][1050],t1[1050],t2[1050];

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(a[i]>a[j]){f[i][j]=1;}
		}
	}
	while(m--){
		scanf("%d%d",&x,&y);
		for(i=1;i<=n;i++){
			t1[i]=(f[i][x]+f[i][y])/2;
			t2[i]=(f[x][i]+f[y][i])/2;
		}
		for(i=1;i<=n;i++){
			f[i][x]=f[i][y]=t1[i];
			f[x][i]=f[y][i]=t2[i];
		}
		f[x][y]=f[y][x]=0.5;
	}
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			res+=f[i][j];
		}
	}
	printf("%.20lf",res);
}