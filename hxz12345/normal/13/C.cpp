#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}long long a[1001010],b[1001010];
long long n,f[5010][3],i,j,ans;
int main() {
	n=read();for (i=1;i<=n;i++) a[i]=read(),b[i]=a[i];sort(b+1,b+n+1);
	//f[i][j] 1~i ij 
	ans=1e18;
	for (j=1;j<=n;j++)
	   {
	   for (i=1;i<=n;i++)
	         {
	         	if (j==1) f[i][j&1]=f[i-1][j&1]+abs(a[i]-b[j]);
	         	else f[i][j&1]=min(f[i-1][j&1]+abs(a[i]-b[j]),f[i-1][1-(j&1)]+abs(a[i]-b[j]));
	         }
	    if (j!=1) for (i=1;i<=n;i++) f[i][j&1]=min(f[i][j&1],f[i][1-(j&1)]);
	    ans=min(ans,f[n][j&1]);
	}
	printf("%lld\n",ans);
	return 0;
}