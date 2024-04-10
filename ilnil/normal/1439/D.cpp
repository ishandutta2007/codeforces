#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define ll long long
using namespace std;
const int N=505;
int n,m,mo;
ll c[N][N],f[N],g[N],f2[N][N],g2[N][N];
int main(){
	scanf("%d%d%d",&n,&m,&mo);
	fo(i,0,n){
		c[i][0]=1;
		fo(j,1,i)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mo;
	}
	f[0]=1;
	fo(i,1,n){
		fo(j,1,i){
			f[i]=(f[i]+f[j-1]*f[i-j]%mo*c[i-1][j-1])%mo;
			g[i]=(g[i]+((f[j-1]*g[i-j]+g[j-1]*f[i-j])%mo*(i+1)+f[j-1]*f[i-j]%mo*(c[j][2]+c[i-j+1][2]))%mo*c[i-1][j-1])%mo;
		}
		f[i]=f[i]*(i+1)%mo;
	}
	f2[0][0]=1;
	fo(i,0,n)fo(j,0,m)if(f2[i][j]){
		f2[i+1][j]=(f2[i+1][j]+f2[i][j])%mo;
		g2[i+1][j]=(g2[i+1][j]+g2[i][j])%mo;
		fo(k,1,min(m-j,n-i)){
			f2[i+k+1][j+k]=(f2[i+k+1][j+k]+f2[i][j]*f[k]%mo*c[j+k][j])%mo;
			g2[i+k+1][j+k]=(g2[i+k+1][j+k]+(g2[i][j]*f[k]+f2[i][j]*g[k])%mo*c[j+k][j])%mo;
		}
	}
	printf("%lld\n",g2[n+1][m]);
}