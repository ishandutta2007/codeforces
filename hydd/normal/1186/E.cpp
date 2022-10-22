#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q,a[2100][2100],s[2100][2100];
ll query(int x,int y){
	int r=(x-1)/(n<<1),c=(y-1)/(m<<1);
	int z=((__builtin_popcount(r^c)&1)?-1:1);
	ll res=1ll*x*y;
	x-=r*(n<<1); y-=c*(m<<1); res+=z*s[x][y];
	if (r&1) res-=z*s[n<<1][y];
	if (c&1) res-=z*s[x][m<<1];
	return res>>1;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			scanf("%1d",&a[i][j]);
			a[i][j+m]=(a[i][j]^1);
			a[i+n][j]=(a[i][j]^1);
			a[i+n][j+m]=a[i][j];
		}
	for (int i=1;i<=(n<<1);i++)
		for (int j=1;j<=(m<<1);j++){
			a[i][j]=(a[i][j]<<1)-1;
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
		}
	int x1,y1,x2,y2;
	while (q--){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("%lld\n",query(x2,y2)-query(x2,y1-1)-query(x1-1,y2)+query(x1-1,y1-1));
	}
	return 0;
}