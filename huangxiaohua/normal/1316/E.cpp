#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
#define cnt(x) __builtin_popcount(x)

int i,j,k,n,m,t,l;
ll f[105000][128][2];
struct sb{
	int a,p[8];
	bool operator<(const sb x)const{return a>x.a;}
}s[100500];

int main(){
	memset(f,-127,sizeof(f));
	f[0][0][0]=0;
	scanf("%d%d%d",&n,&m,&l);
	for(i=1;i<=n;i++){
		scanf("%d",&s[i].a);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&s[i].p[j]);
		}
	}
	sort(s+1,s+n+1);
	for(i=1;i<=n;i++){
		for(j=0;j<b(m+1);j++){
			f[i][j][1]=f[i-1][j][1];
			f[i][j][0]=f[i-1][j][0];
			if(cnt(j)+l==i){
				f[i][j][1]=max(f[i][j][1],f[i-1][j][0]+s[i].a);
			}
			if(cnt(j)+l>i){
				f[i][j][0]=max(f[i][j][0],f[i-1][j][0]+s[i].a);
			}
			for(k=1;k<=m;k++){
				if(!(j&b(k))){continue;}
				f[i][j][1]=max(f[i][j][1],f[i-1][j^b(k)][1]+s[i].p[k]);
				f[i][j][0]=max(f[i][j][0],f[i-1][j^b(k)][0]+s[i].p[k]);
			}
			//printf("%d %d %d %d\n",i,j,f[i][j][0],f[i][j][1]);
		}
	}
	printf("%lld",f[n][b(m+1)-1][1]);
}