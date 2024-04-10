#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,m,a[2050],b[2050],f[2050][2050];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	memset(f,0x7f,sizeof(f));
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	memset(f[0],0,sizeof(f[0]));
	for(i=1;i<=n;i++){
		for(j=i;j<=m;j++){
			f[i][j]=min(f[i][j-1],max(f[i-1][j-1],abs(a[i]-b[j])+abs(b[j]-k)));
		}
	}
	printf("%d",f[n][m]);
}