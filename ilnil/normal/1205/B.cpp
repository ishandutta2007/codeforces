#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int N=2e5+5,M=200;
int n,cnt,nn;
int f[M][M],v[M][M];
ll a[N],b[N];
int main(){
	scanf("%d",&n);
	fo(i,1,n)scanf("%I64d",&a[i]);
	bool can=0;
	fo(j,0,60){
		cnt=0;
		fo(i,1,n)
			if(a[i]&(1LL<<j))++cnt;
		if(cnt>=3){
			can=1;
			break;
		}
	}
	if(can){
		printf("3");
		return 0;
	}
	fo(i,1,n)if(a[i])b[++nn]=a[i];
	fo(i,1,nn)fo(j,1,nn)f[i][j]=10000,v[i][j]=10000;
	fo(i,1,nn)f[i][i]=0;
	fo(i,1,nn)fo(j,i+1,nn)
		if(b[i]&b[j]){
			f[i][j]=f[j][i]=1;
			v[i][j]=v[j][i]=1;
		}
	int ans=10000;
	fo(k,1,nn){
		fo(i,1,k-1)
			fo(j,1,k-1)
				if(i!=j)
					ans=min(ans,v[k][i]+v[k][j]+f[i][j]);
		fo(i,1,nn)if(i!=k)
			fo(j,1,nn)if(i!=j&&k!=j)
				if(f[i][k]!=10000&&f[k][j]!=10000){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
	}
	if(ans==10000)printf("-1");
	else printf("%d",ans);
}