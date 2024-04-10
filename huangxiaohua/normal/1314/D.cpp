#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,sb[85][85],f[11][85],res=2e9;
bitset<85>b;
mt19937_64 r(chrono::steady_clock::now().time_since_epoch().count()+1);

int main(){
	long c=clock();
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&sb[i][j]);
		}
	}
	while(clock()-c<=2800){
		for(i=1;i<=n;i++){
			b[i]=r()&1;
		}
		memset(f,0x3f,sizeof(f));
		f[0][1]=0;
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				for(k=1;k<=n;k++){
					if(b[j]!=b[k]){
						f[i][j]=min(f[i][j],f[i-1][k]+sb[k][j]);
					}
				}
			}
		}
		res=min(res,f[m][1]);
	}
	printf("%d",res);
}