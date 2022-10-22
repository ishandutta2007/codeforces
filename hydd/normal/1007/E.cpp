#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1ll<<60;
int n,t,k;
ll a[310],b[310],c[310],sa[310],sb[310],sc[310];
ll f[310][310][2],g[310][310][2];
int main(){
	scanf("%d%d%d",&n,&t,&k);
	for (int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
	n++; a[n]=INF; b[n]=0; c[n]=INF;
	for (int i=1;i<=n;i++){
		sa[i]=sa[i-1]+a[i];
		sb[i]=sb[i-1]+b[i];
		sc[i]=sc[i-1]+c[i];
	}	
	for (int i=1;i<=n;i++){
		for (int j=0;j<=t;j++){
			for (int z=0;z<=1;z++){
				f[i][j][z]=INF; g[i][j][z]=INF;
				if (f[i-1][j][z]!=INF&&a[i]*z+b[i]*j<=c[i]){
					f[i][j][z]=f[i-1][j][z];
					ll val=(z*sa[i-1]+j*sb[i]+k-1)/k;
					if (val*k<=z*sa[i]+j*sb[i]) g[i][j][z]=val;
				}
				for (int r=0;r<j;r++){
					if (g[i][r][z]==INF) continue;
					
					ll rem=z*sa[i]+r*sb[i]-k*g[i][r][z];
					ll x=(max(0ll,rem+(j-r)*b[i]-c[i])+k-1)/k;
					if (x*k>rem) continue;
					
					if (f[i-1][j-r][0]==INF) continue;
					f[i][j][z]=min(f[i][j][z],g[i][r][z]+x+f[i-1][j-r][0]);
					
					ll val=((j-r)*sb[i-1]+k-1)/k;
					if (val*k>(j-r)*sb[i]+rem-x*k) continue;
					g[i][j][z]=min(g[i][j][z],g[i][r][z]+x+val);
				}
			}
		}
	}
	printf("%lld\n",f[n][t][1]);
	return 0;
}