#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=200005;
int n,ans;
LL s[N],f[18][N];
LL qry(int l,int r){
	int t=r-l+1,v=std::__lg(t);
	return std::__gcd(f[v][l],f[v][r-(1<<v)+1]);
}
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;i++)scanf("%lld",s+i);
		if(n==1){
			puts("1");
			continue;
		}
		for(int i=1;i<=n-1;i++)s[i]=std::abs(s[i]-s[i+1]);
		n--;
		for(int i=1;i<=n;i++)f[0][i]=s[i];
		for(int i=0;i<17;i++) for(int j=1;j<=n-(1<<i+1)+1;j++)f[i+1][j]=std::__gcd(f[i][j],f[i][j+(1<<i)]);
		int j=0;
		for(int i=1;i<=n;i++){
			for(j=std::max(j,i-1);j<n&&qry(i,j+1)!=1;j++);
			ans=std::max(ans,j-i+1);
		}
		printf("%d\n",ans+1);
	}
}