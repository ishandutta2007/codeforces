#include<bits/stdc++.h>

using namespace std;
#define LL long long
const int N=3e5+10;
const LL INF=1e18;
int P;
int add(int &x,int y){
	x+=y;if(x>=P)x-=P;
}
int n;
int B[410];
int C[410][410];
int F[4][410][410];
void MAIN(){
	scanf("%d%d",&n,&P);
	B[0]=1;
	for(int i=1;i<=n;++i){
		B[i]=B[i-1]<<1;
		if(B[i]>=P)B[i]-=P;
	}
	for(int i=0;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			if(C[i][j]>=P) C[i][j]-=P;
		}
	}
	F[0][0][1]=1;
	for(int i=1;i<n;++i){
		for(int j=0;j<=n;++j){
			for(int k=1;k<=n;++k){
				if(!F[0][j][k]) continue;
				if(i+1<=n){
					add(F[1][j][k+1],F[0][j][k]);
				}
				if(i+2<=n){
					add(F[2][j+k][1],(LL)F[0][j][k]*B[k-1]%P*C[j+k][j]%P);
				}
			}
		}
		for(int j=0;j<=n;++j){
			for(int k=1;k<=n;++k){
				F[0][j][k]=F[1][j][k];
				F[1][j][k]=F[2][j][k];
				F[2][j][k]=0;
			}
		}
	}
	int ans=0;
	for(int j=0;j<=n;++j){
		for(int k=1;k<=n;++k){
			if(!F[0][j][k]) continue;
			add(ans,(LL)F[0][j][k]*B[k-1]%P*C[j+k][j]%P);
		}
	}
	
	printf("%d\n",ans);
	return;
}

int main(){
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;
}