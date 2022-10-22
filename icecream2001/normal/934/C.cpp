#include<cstdio>
#include<cstring>
#define LL long long
#define N 2010
using namespace std;
int n,m,ans=0;
int a[N],b[N],c[N],d[N],e[N],f[N],g[N];
int main(){
	scanf("%d",&n);m=n>>1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1];
		if(a[i]==1) b[i]++;
	}
	for(int i=n;i>=1;i--){
		c[i]=c[i+1];
		if(a[i]==2) c[i]++;
	}
	for(int i=0;i<=n;i++){
		if(b[i]+c[i+1]>ans) ans=b[i]+c[i+1];
	}
	if(!m){
		printf("%d\n",ans);return 0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=i;j++){
			e[j]=e[j-1];
			if(a[j]==1) e[j]--;else e[j]++;
			d[n-j+1]=d[n-j+2];
			if(a[n-j+1]==2) d[n-j+1]--;else d[n-j+1]++;
			f[j]=e[j];g[n-j+1]=d[n-j+1];
		}
		for(int j=i+1;j<=n;j++){
			e[j]=e[j-1];
			if(a[j]==1) e[j]--;else e[j]++;
			if(a[j-i]==1) e[j]++;else e[j]--;
			d[n-j+1]=d[n-j+2];
			if(a[n-j+1]==2) d[n-j+1]--;else d[n-j+1]++;
			if(a[n-j+1+i]==2) d[n-j+1]++;else d[n-j+1]--;
			f[j]=e[j];g[n-j+1]=d[n-j+1];
		}
		for(int j=i+1;j<=n;j++){
			if(e[j-1]>e[j]) e[j]=e[j-1];
			if(d[n-j+2]>d[n-j+1]) d[n-j+1]=d[n-j+2];
		}
		for(int j=i;j<=n-i;j++){
			if(b[j]+c[j+1]+f[j]+d[j+1]>ans) ans=b[j]+c[j+1]+f[j]+d[j+1];
			if(b[j]+c[j+1]+g[j+1]+e[j]>ans) ans=b[j]+c[j+1]+g[j+1]+e[j];
		}
	}
	printf("%d\n",ans);
	return 0;
}