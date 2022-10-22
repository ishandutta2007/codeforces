#include <cstdio>
const int Maxn=3000;
const int Mod=998244353;
int n,m;
char s[Maxn+5],t[Maxn+5];
int f[Maxn+5][Maxn+5],g[Maxn+5];
int d[Maxn+5][Maxn+5],p[Maxn+5];
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	scanf("%s",t+1);
	while(t[++m]!='\0');
	m--;
	g[m+1]=1;
	for(int l=1;l<=m;l++){
		for(int i=1,j;(j=i+l-1)<=m;i++){
			if(i==j){
				if(t[i]==s[1]){
					f[i][j]=2;
					if(j==m){
						g[m]=1;
					}
				}
				else{
					f[i][j]=0;
				}
			}
			if(i>1&&s[l+1]==t[i-1]){
				f[i-1][j]=(f[i-1][j]+f[i][j])%Mod;
			}
			if(j<m&&s[l+1]==t[j+1]){
				f[i][j+1]=(f[i][j+1]+f[i][j])%Mod;
				if(j+1==m){
					g[i]=(g[i]+f[i][j])%Mod;
				}
			}
		}
	}
	d[n+1][0]=1;
	for(int i=n;i>0;i--){
		d[i][0]=n-i+2;
		for(int j=1;j<=m;j++){
			d[i][j]=(d[i][j]+d[i+1][j])%Mod;
			if(j>0&&s[i]==t[j]){
				d[i][j]=(d[i][j]+d[i+1][j-1])%Mod;
			}
		}
	}
	int ans=0;
	for(int i=m;i>0;i--){
		ans=(ans+1ll*g[i]*d[(m-i+1)+1][i-1]%Mod)%Mod;
	}
	p[0]=1;
	for(int i=1;i<=n;i++){
		p[i]=(p[i-1]<<1)%Mod;
	}
	for(int i=1;i<=n;i++){
		ans=(ans+1ll*p[i-1]*(d[i][m]-d[i+1][m])%Mod)%Mod;
	}
	printf("%d\n",ans);
	return 0;
}