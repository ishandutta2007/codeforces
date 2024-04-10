#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,m1,a[5050],b[5050],f[5050][5050];

int main(){
	memset(f,0x3f,sizeof(f));
	memset(f[0],0,sizeof(f[0]));
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		if(k){a[++m]=i;}
		else{b[++m1]=i;}
	}
	for(i=1;i<=m;i++){
		for(j=i;j<=m1;j++){
			f[i][j]=min(f[i][j],f[i-1][j-1]+abs(a[i]-b[j]));
			f[i][j]=min(f[i][j],f[i][j-1]);
			//printf("%d %d %d\n",i,j,f[i][j]);
		}
	}
	if(!m){puts("0");return 0;}
	printf("%d",f[m][m1]);
}