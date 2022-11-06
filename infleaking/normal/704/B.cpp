#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5010;
ll f[N][N],a[N],b[N],c[N],d[N],p[N],s,e,n;
void cmin(ll &a,ll b){
	a=a<b?a:b;
}
int main(){
	cin>>n>>s>>e;
	for (int i=1;i<=n;i++)scanf("%d",&p[i]);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)scanf("%d",&b[i]);
	for (int i=1;i<=n;i++)scanf("%d",&c[i]);
	for (int i=1;i<=n;i++)scanf("%d",&d[i]);
	memset(f,1,sizeof f);
	f[0][0]=0;
//	if (e<s){
//		reverse(a+1,a+n+1);
//		reverse(b+1,b+n+1);
//		reverse(c+1,c+n+1);
//		reverse(d+1,d+n+1);
//		reverse(p+1,p+n+1);
//		for (int i=1;i<=n;i++)
//			p[i]=1000000001-p[i],swap(a[i],b[i]),swap(c[i],d[i]);
//		s=n-s+1;
//		e=n-e+1;
//	}
	if (s<e){
	for (int i=1;i<=n;i++){
		for (int j=0;j<=i;j++){
			if (i==s){
				cmin(f[i][j+1],f[i-1][j]+(-p[i]+d[i]));
				cmin(f[i][j],f[i-1][j]+(p[i]+c[i]));
				continue;
			}
			if (i==e){
				cmin(f[i][j],f[i-1][j]+(-p[i]+b[i]));
				if (j)cmin(f[i][j-1],f[i-1][j]+(p[i]+a[i]));
				continue;
			}
			cmin(f[i][j+1],f[i-1][j]+(-2*p[i]+b[i]+d[i]));
			cmin(f[i][j],f[i-1][j]+a[i]+d[i]);
			if (i<s||i>e||j>1)
			cmin(f[i][j],f[i-1][j]+b[i]+c[i]);
			if (j)cmin(f[i][j-1],f[i-1][j]+(2*p[i]+c[i]+a[i]));
		}
		if (i==n)
			cout<<f[n][0]<<endl;
		f[i][0]=f[0][1];
	}
	return 0;
	}
	else {
	for (int i=1;i<=n;i++){
		for (int j=0;j<=i;j++){
			if (i==s){
				cmin(f[i][j],f[i-1][j]+(-p[i]+d[i]));
				if (j)cmin(f[i][j-1],f[i-1][j]+(p[i]+c[i]));
				continue;
			}
			if (i==e){
				cmin(f[i][j+1],f[i-1][j]+(-p[i]+b[i]));
				cmin(f[i][j],f[i-1][j]+(p[i]+a[i]));
				continue;
			}
			cmin(f[i][j+1],f[i-1][j]+(-2*p[i]+b[i]+d[i]));
			cmin(f[i][j],f[i-1][j]+b[i]+c[i]);
			if (i<e||i>s||j>1)
			cmin(f[i][j],f[i-1][j]+a[i]+d[i]);
//			cmin(f[i][j],f[i-1][j]+min(b[i]+c[i],a[i]+d[i]));
			if (j)cmin(f[i][j-1],f[i-1][j]+(2*p[i]+c[i]+a[i]));
		}
		if (i==n)
			cout<<f[n][0]<<endl;
		f[i][0]=f[0][1];
	}
	return 0;	
	}
}