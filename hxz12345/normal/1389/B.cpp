#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
//f[i][j] 
long long Testing,n,m,K,a[1001010],f[1001010][8],ans,i,j;
int main() {
	int Testing=read();
	for (;Testing;Testing--){
		n=read();m=read();K=read();
		for (i=1;i<=n;i++) a[i]=read();
		for (i=0;i<=m;i++)
		   for (j=0;j<=K;j++)
		      f[i][j]=-1;
		f[0][0]=a[1];ans=-1;
		for (i=1;i<=m;i++)
		   for (j=0;j<=K;j++)
		        {
		        	if (j==0) f[i][j]=f[i-1][j]+a[i+1];
		        	else {
		        		if ((f[i-1][j]!=-1)&&(i+1-2*j>0)) f[i][j]=f[i-1][j]+a[i+1-2*j];
		        		if ((f[i-1][j-1]!=-1)&&(i+1-2*j>0)) f[i][j]=max(f[i][j],f[i-1][j-1]+a[i+1-2*j]);
 					}
 					//1+i-j-j=1+3-2=2
 					//2 1
 				if (i==m) ans=max(ans,f[i][j]);
				}
		printf("%lld\n",ans);
		}
    return 0;
}