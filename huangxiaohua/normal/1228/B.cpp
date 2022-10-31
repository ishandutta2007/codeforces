#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,j,k,n,m,t,a[1050],b[1050],f[1050][1050];
ll res=1;

bool chk1(int x){
	for(int i=1;;i++){
		if(!f[x][i]){
			return (i-1)==a[x];
		}
	}
}

bool chk2(int x){
	for(int i=1;;i++){
		if(!f[i][x]){
			return (i-1)==b[x];
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(j=1;j<=a[i];j++){
			f[i][j]=1;
		}
	}
	for(i=1;i<=m;i++){
		scanf("%d",&b[i]);
		for(j=1;j<=b[i];j++){
			f[j][i]=1;
		}
	}
	for(i=1;i<=n;i++){
		if(!chk1(i)){puts("0");return 0;}
	}
	for(i=1;i<=m;i++){
		if(!chk2(i)){puts("0");return 0;}
	}
	//puts("a");
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			//printf("%d ",f[i][j]);
			if(f[i][j]||i==1||j==1||j==a[i]+1||i==b[j]+1){
				//printf("%d %d\n",i,j);
				continue;
			}
			res=(res+res)%M;
		}
		//puts("");
	}
	printf("%lld",res);
}