#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
const int N=505;
int n,k,d[2][N][N],e[N],s;
void upd(int &a,int b){a+=b;if(p<=a)a-=p;}
int mul(int a,int b){return ((long long)a*b)%p;}
int main(){
	scanf("%d%d",&n,&k),d[0][0][0]=1;
	for(int i=0;i<n;i++){
		memset(d[1],0,sizeof(d[1]));
		for(int k=0;k<=i;k++)for(int j=0;j<=k;j++)
			upd(d[1][j+1][max(k,j+1)],d[0][j][k]),upd(d[1][1][max(k,1)],d[0][j][k]);
		for(int k=0;k<=i+1;k++)for(int j=0;j<=k;j++)d[0][j][k]=d[1][j][k];
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)upd(e[i],d[0][j][i]);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i*j<k)
		upd(s,mul(e[i],e[j]));
	printf("%d",mul(s,499122177));
	return 0;
}