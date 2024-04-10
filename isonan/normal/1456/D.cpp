#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long

int n,t[5010],x[5010];
long long g[5010],walk[5010][5010];
bool T[5010][5010];
bool good[5010],h[5010];
long long abs(long long a){
	return a<0?-a:a;
}
signed main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%lld",&n);
	++n;
	for(int i=2;i<=n;i++)scanf("%lld%lld",t+i,x+i);
	memset(g,0x7f,sizeof g);
	long long inf=g[0];
	for(int i=1;i<=n;i++){
		walk[i][i]=0;
		for(int j=i+1;j<=n;j++)
			walk[i][j]=walk[i][j-1]+abs(x[j]-x[j-1]);
	}
	for(int i=n-1;i;i--){
		T[i][i+1]=(t[i]+abs(x[i]-x[i+1])<=t[i+1]);
//		printf("%d %d %d\n",i,i+1,T[i][i+1]);
	}
	for(int i=1;i<=n;i++)
		for(int j=i+2;j<=n;j++){
			T[i][j]=T[j-1][j]&T[i][j-1];
//			printf("%d %d %d\n",i,j,T[i][j]);
		}
	g[1]=0;
	good[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i-1;j++){
			if(good[j]&&t[j]+abs(x[j]-x[i])<=t[i]&&t[j]+abs(x[j]-x[i])+abs(x[i]-x[j+1])<=t[j+1]&&(j+1==i-1||T[j+1][i-1])){
				h[i]=1;
			}
			if(g[j]<=t[j]&&g[j]+abs(x[j]-x[i])<=t[i]&&std::max(g[j]+abs(x[j]-x[i]),t[j])+abs(x[i]-x[j+1])<=t[j+1]&&(j+1==i-1||T[j+1][i-1])){
				h[i]=1;
			}
			if(h[j]&&t[j-1]+abs(x[j-1]-x[i])<=t[i]&&std::max(t[j-1]+abs(x[j-1]-x[i]),t[j])+abs(x[i]-x[j+1])<=t[j+1]&&(j+1==i-1||T[j+1][i-1])){
				h[i]=1;
			}
		}
		if(good[i-1])g[i]=std::min(g[i],1ll*t[i-1]+abs(x[i]-x[i-1]));
		if(g[i-1]<=t[i-1])g[i]=std::min(g[i],std::max(1ll*t[i-1],g[i-1]+abs(x[i]-x[i-1])));
		if(h[i-1]&&i>2&&t[i-2]+abs(x[i]-x[i-2])<=t[i])good[i]=1,g[i]=std::min(g[i],std::max(1ll*t[i-1],t[i-2]+abs(x[i]-x[i-2])));
		if(good[i-1]&&T[i-1][i])good[i]=1;
//		printf("%lld %lld %lld\n",g[i],good[i],h[i]);
	}
	if(h[n]||good[n]||g[n]<=t[n])puts("YES");
	else puts("NO");
}