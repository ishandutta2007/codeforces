#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353
int i,j,k,n,m,t,x,y;
ll fx[4050][4050],fy[4050][4050],res,xx,yy;
int vx[4050],vy[4050];
ll jc[10050],inv[10050];
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[n-m]%M;}

ll get(int x,int y){
	ll res;
	res=fx[n][x]*fy[m][y]%M;
	res=res*c(xx-2*x,y)%M;
	res=res*c(yy-2*y,x)%M;
	//if(res){printf("b%d %d %d\n",x,y,res);}
	return res;
}

int main(){
	jc[0]=inv[0]=1;
	for(i=1;i<=10000;i++){jc[i]=jc[i-1]*i%M;}
	inv[10000]=ksm(jc[10000],M-2);
	for(i=9999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	
	scanf("%d%d%d",&n,&m,&t);t*=2;
	xx=n;yy=m;
	while(t--){
		scanf("%d%d",&x,&y);
		vx[x]=1;
		vy[y]=1;
	}
	fx[0][0]=fy[0][0]=1;
	fx[1][0]=fy[1][0]=1;
	for(i=1;i<=n;i++){xx-=vx[i];}
	for(i=1;i<=m;i++){yy-=vy[i];}
	for(i=2;i<=n;i++){
		if(vx[i]||vx[i-1]){
			for(j=0;j<=n;j++){
				fx[i][j]=fx[i-1][j];
			}
		}
		else{
			for(j=0;j<=n;j++){
				fx[i][j]=fx[i-1][j];
				if(j){fx[i][j]+=fx[i-2][j-1];}
				fx[i][j]%=M;
			}
		}
	}
	for(i=2;i<=m;i++){
		if(vy[i]||vy[i-1]){
			for(j=0;j<=m;j++){
				fy[i][j]=fy[i-1][j];
			}
		}
		else{
			for(j=0;j<=m;j++){
				fy[i][j]=fy[i-1][j];
				if(j){fy[i][j]+=fy[i-2][j-1];}
				fy[i][j]%=M;
			}
		}
	}
	/*for(i=0;i<=n;i++){
		printf("a%d %d %d\n",i,fx[n][i],fy[m][i]);
	}*/
	for(i=0;i<=3600;i++){
		for(j=0;j<=3600;j++){
			res+=get(i,j);res%=M;
		}
	}
	printf("%lld",res);
}