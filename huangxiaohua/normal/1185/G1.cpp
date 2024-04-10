#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007
int i,j,k,n,m,t,it;
ll jc[666],f1[55][2555],f2[55][2555],f3[55][2555],res;
ll f12[55][55][2555],g[66][66][66][10],tmp2,tmp;
vector<int> v1,v2,v3;

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
				//printf("a%d %d %d %d %d %d %d\n",i,j,k,l,g[j][k][l][1],g[j][k][l][2],g[j][k][l][3]);
			}
		}
	}
}

int main(){
	init();
	
	
	scanf("%d%d",&t,&n);
	while(t--){
		scanf("%d%d",&i,&j);
		if(j==1){v1.push_back(i);}
		if(j==2){v2.push_back(i);}
		if(j==3){v3.push_back(i);}
	}

	f1[0][0]=1;
	for(auto i:v1){
		for(j=50;j>=1;j--){
			for(k=n;k>=i;k--){
				f1[j][k]=su(f1[j][k],f1[j-1][k-i]);
			}
		}
	}
	
	f2[0][0]=1;
	for(auto i:v2){
		for(j=50;j>=1;j--){
			for(k=n;k>=i;k--){
				f2[j][k]=su(f2[j][k],f2[j-1][k-i]);
			}
		}
	}
	
	f3[0][0]=1;
	for(auto i:v3){
		for(j=50;j>=1;j--){
			for(k=n;k>=i;k--){
				f3[j][k]=su(f3[j][k],f3[j-1][k-i]);
			}
		}
	}
	
	for(i=0;i<=50;i++){
		for(j=0;j<=n;j++){
			f12[i][0][j]=f1[i][j];
		}
	}
	for(auto ii:v2){
		for(i=0;i<=50;i++){
			for(j=50;j>=1;j--){
				for(k=n;k>=i;k--){
					f12[i][j][k]=su(f12[i][j][k],f12[i][j-1][k-ii]);
				}
			}
		}
	}
	
	res=su(res,f1[1][n]);
	res=su(res,f2[1][n]);
	res=su(res,f3[1][n]);
	
	for(i=1;i<=25;i++){
		for(j=0;j<=n;j++){
			res=su(res,f1[i][j]*f2[i][n-j]%M*jc[i]%M*jc[i]%M*2%M);
			res=su(res,f1[i][j]*f3[i][n-j]%M*jc[i]%M*jc[i]%M*2%M);
			res=su(res,f2[i][j]*f3[i][n-j]%M*jc[i]%M*jc[i]%M*2%M);
			
			res=su(res,f1[i][j]*f3[i+1][n-j]%M*jc[i]%M*jc[i+1]%M);
			res=su(res,f1[i][j]*f2[i+1][n-j]%M*jc[i]%M*jc[i+1]%M);
			res=su(res,f2[i][j]*f1[i+1][n-j]%M*jc[i]%M*jc[i+1]%M);
			res=su(res,f2[i][j]*f3[i+1][n-j]%M*jc[i]%M*jc[i+1]%M);
			res=su(res,f3[i][j]*f1[i+1][n-j]%M*jc[i]%M*jc[i+1]%M);
			res=su(res,f3[i][j]*f2[i+1][n-j]%M*jc[i]%M*jc[i+1]%M);
		}
	}
	
	
	for(i=1;i<=50;i++){
		for(j=1;j<=50-i;j++){
			for(k=1;k<=50-i-j;k++){
				tmp=jc[i]%M*jc[j]%M*jc[k]%M;
				tmp2=(g[i][j][k][1]+g[i][j][k][2]+g[i][j][k][3])%M;
				//printf("%d %d %d %d %d\n",i,j,k,tmp,tmp2);
				for(int l=1;l<=n;l++){
					res=su(res,tmp2*f12[i][j][l]%M*f3[k][n-l]%M*tmp%M);
					
					/*if(tmp&&tmp2&&f12[i][j][l]&&f3[k][n-l]){
						printf("%d %d %d %d %d %d %d %d\n",i,j,k,l,tmp,tmp2,f12[i][j][l],f3[k][n-l]);
					}*/
				}
			}
		}
	}
	printf("%lld",res%M);
}