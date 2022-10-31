#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;

#define M 1000000007
int i,j,k,n,m,t,i0,i1,k1,k2;
ll f[2][25][2],res;
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
ll max(ll a,ll b){return (a>b)?a:b;}
int main(){
	scanf("%d",&n);
	k=n;
	while(k){m++;k/=2;}m--;
	f[0][m+1][0]=1;
	for(i=1;i<=n;i++){
		i1=(i&1);i0=1-i1;
		memset(f[i1],0,sizeof(f[i1]));
		for(j=0;j<=m;j++){
			k=n/(1<<j);
			k1=k-n/(1<<(j+1));
			f[i1][j][0]=su(f[i1][j][0],f[i0][j+1][0]*k1%M);
			f[i1][j][0]=su(f[i1][j][0],f[i0][j][0]*max(0,k-i+1)%M);
		}
		if(i==n){
			res=su(res,f[i1][0][0]);
		}
	}
	m--;
	if((1<<m)*3>n){goto aaa;}
	memset(f,0,sizeof(f));
	f[0][m+1][1]=1;
	for(i=1;i<=n;i++){
		i1=(i&1);i0=1-i1;
		memset(f[i1],0,sizeof(f[i1]));
		for(j=0;j<=m;j++){
			k=n/(1<<j);
			k1=k-n/(1<<(j+1));
			k2=k-(n/3)/(1<<j);
			f[i1][j][0]=su(f[i1][j][0],f[i0][j+1][0]*k1%M);
			f[i1][j][0]=su(f[i1][j][0],f[i0][j][1]*k2%M);
			f[i1][j][0]=su(f[i1][j][0],f[i0][j][0]*max(0,k-i+1)%M);
			
			k=(n/3)/(1<<j);
			k1=k-(n/3)/(1<<(j+1));
			f[i1][j][1]=su(f[i1][j][1],f[i0][j+1][1]*k1%M);
			f[i1][j][1]=su(f[i1][j][1],f[i0][j][1]*max(0,k-i+1)%M);
		}
		if(i==n){
			res=su(res,f[i1][0][0]);
		}
	}
	aaa:;
	printf("%d",res);
}