#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=505;
int n,s[N][N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++) for(int j=1;j<=n*2;j++)scanf("%d",&s[i][j]);
		LL t=std::min(std::min(std::min(s[1][n+1],s[1][n*2]),std::min(s[n][n+1],s[n][n*2])),std::min(std::min(s[n+1][1],s[n+1][n]),std::min(s[n*2][1],s[n*2][n])));
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)t+=s[i+n][j+n];
		printf("%lld\n",t);
	}
}