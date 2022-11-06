#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
//
long long j,n,i,ans,G,f[101][10101],sufa[1001010],sufb[1001010],a[1001010],b[1001010];
void Main(){
	n=read();
	for (i=1;i<=n;i++) a[i]=read();
	for (i=1;i<=n;i++) b[i]=read();ans=0;
	
	if (n==1){
		puts("0");return ;
	}
	sufa[n+1]=sufb[n+1]=0;
	for (i=n;i>=1;i--) sufa[i]=sufa[i+1]+a[i],sufb[i]=sufb[i+1]+b[i];	for (i=1;i<=n;i++) ans+=(n-1)*(a[i]*a[i]+b[i]*b[i]);
	//f[i][x] isufa[i]=x
	for (i=1;i<=n;i++)
	  for (j=0;j<=10000;j++)
	       f[i][j]=-1;
	f[n][a[n]]=0;f[n][b[n]]=0;
	for (i=n-1;i>=1;i--){
		for (j=0;j<=10000;j++)
		    if (f[i+1][j]!=-1)
		        {
		        	f[i][j+a[i]]=max(f[i][j+a[i]],f[i+1][j]+a[i]*j+b[i]*(sufa[i+1]+sufb[i+1]-j));
		        	f[i][j+b[i]]=max(f[i][j+b[i]],f[i+1][j]+b[i]*j+a[i]*(sufa[i+1]+sufb[i+1]-j));
				}
	}
G=1e18;
for (i=0;i<=10000;i++) if (f[1][i]!=-1) G=min(G,f[1][i]);
G=G*2+ans;
printf("%lld\n",G);
}
int main() {
	int Testing=read();
	for (;Testing;Testing--) Main();
	return 0;
}