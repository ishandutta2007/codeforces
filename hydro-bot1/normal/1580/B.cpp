// Hydro submission #631c19be9b59fa12452c236e@1662785982888
#include<bits/stdc++.h>
using namespace std;
#define maxn 109
int n,m,k,p;
long long f[maxn][maxn][maxn],c[maxn][maxn],fac[maxn]; 
inline int read(){
	int sum=0,fh=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')fh=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum*=10;
		sum+=c-'0';
		c=getchar();
	}
	return sum*fh;
}
long long gsum(int i,int j,int k){
	if(!j&&(k>i||k<1))return fac[i];
	return f[i][j][k];
}
int main(){
//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);
	n=read();m=read();k=read();p=read();
	fac[0]=c[0][0]=f[1][1][1]=1;
	for(int i=1;i<=n;i++)c[i][0]=1,fac[i]=fac[i-1]*i%p;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
			c[i][j]%=p;
		}
	}
	for(int i=2;i<=n;i++)
	for(int j=0;j<=min(i,k);j++)
	for(int k=1;k<=min(i-j+1,m);k++){
		int rk=j-(k==1);
		f[i][j][k]=(gsum(i-1,rk,k-1)*2)%p;
	for(int ls=2;ls<=i-1;ls++){
		int rs=i-ls;
		for(int lt=0;lt<=min(rk,ls);lt++){
			int rt=rk-lt;
			long long a=gsum(ls-1,lt,k-1),b=gsum(rs,rt,k-1);
			if(a&&b){
			f[i][j][k]+=a*b%p*c[i-1][ls-1]%p;
			f[i][j][k]%=p;
			}
		}
	}
	}
	cout<<f[n][k][m];
//	  fclose(stdin);
//    fclose(stdout);
	return 0;
}