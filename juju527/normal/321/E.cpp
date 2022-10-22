#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=4005,maxk=805;
int s[maxn][maxn],w[maxn][maxn];
int f[maxn][maxk],p[maxn][maxk];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int main(){
	int n,k;
	n=read();k=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			s[i][j]=s[i][j-1]+read();
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			w[i][j]=w[i][j-1]+s[j][j]-s[j][i];
		}
	for(int i=1;i<=n;i++)w[0][i]=w[1][i]+s[1][i];
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int j=1;j<=k;j++){
		p[n+1][j]=n;
		for(int i=n;i>=1;i--){
			for(int l=p[i][j-1];l<=min(p[i+1][j],i-1);l++){
				if(f[i][j]>f[l][j-1]+w[l][i]){
					f[i][j]=f[l][j-1]+w[l][i];
					p[i][j]=l;
				}
			}
		}
	}
	printf("%d\n",f[n][k]);
	return 0;
}