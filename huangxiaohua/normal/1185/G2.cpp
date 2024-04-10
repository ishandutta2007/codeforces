#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007
int i,j,k,l,n,m,t,it;
ll jc[666],f[4][55][2555],res;
ll f12[55][55][2555],g[66][66][66][10],tmp2,tmp;
vector<int> v;

ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

void init(){
	jc[0]=1;
	for(i=1;i<=66;i++){
		jc[i]=jc[i-1]*i%M;
	}
	
	int i,j,k,l,r;
	g[0][0][1][3]=1;
	g[0][1][0][2]=1;
	g[1][0][0][1]=1;
	
	for(i=1;i<=50;i++){
		for(j=0;j<=i;j++){
			for(k=0;j+k<=i;k++){
				l=i-j-k;
				g[j+1][k][l][1]=su(g[j+1][k][l][1],g[j][k][l][2]);
				g[j+1][k][l][1]=su(g[j+1][k][l][1],g[j][k][l][3]);
				
				g[j][k+1][l][2]=su(g[j][k+1][l][2],g[j][k][l][1]);
				g[j][k+1][l][2]=su(g[j][k+1][l][2],g[j][k][l][3]);
				
				g[j][k][l+1][3]=su(g[j][k][l+1][3],g[j][k][l][1]);
				g[j][k][l+1][3]=su(g[j][k][l+1][3],g[j][k][l][2]);
			}
		}
	}
}

int main(){
	init();
	f[1][0][0]=f[2][0][0]=f[3][0][0]=1;
	scanf("%d%d",&t,&n);
	while(t--){
		scanf("%d%d",&i,&j);
		for(k=50;k>=1;k--){
			for(l=n;l>=i;l--){
				f[j][k][l]=su(f[j][k][l],f[j][k-1][l-i]);
			}
		}
		if(j==2){v.push_back(i);}
	}

	for(i=0;i<=50;i++){
		for(j=0;j<=n;j++){
			f12[i][0][j]=f[1][i][j];
		}
	}
	for(auto ii:v){
		for(i=0;i<=50;i++){
			for(j=50;j>=1;j--){
				for(k=n;k>=i;k--){
					f12[i][j][k]=su(f12[i][j][k],f12[i][j-1][k-ii]);
				}
			}
		}
	}
	for(i=0;i<=50;i++){
		for(j=0;j<=50-i;j++){
			for(k=0;k<=50-i-j;k++){
				tmp=jc[i]%M*jc[j]%M*jc[k]%M;
				tmp2=(g[i][j][k][1]+g[i][j][k][2]+g[i][j][k][3])%M;
				if(!tmp||!tmp2){continue;}
				for(int l=0;l<=n;l++){
					res=su(res,tmp2*f12[i][j][l]%M*f[3][k][n-l]%M*tmp%M);
				}
			}
		}
	}
	printf("%lld",res%M);
}