//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
#define N 2190002
char s[N];
int a[N],n,f[15][15],g[15][15],ans;

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);for(int i=1;i<=n;++i)a[i]=s[i]-48;
	for(int x=0;x<=9;++x)
	for(int y=0;y<=9;++y){
//		memset(f,0,sizeof(f)); //-1
		for(int i=0;i<=9;++i)
		for(int j=0;j<=9;++j)f[i][j]=9999;
//		for(int i=0;i<=9;++i)f[i][i]=0;
		for(int i=0;i<=9;++i){
			f[i][(i+x)%10]=1;
			f[i][(i+y)%10]=1;
		} //floy  zuixiaohuan //zhao sanyuanhuan siyuanhuan
		for(int k=0;k<=9;++k)
		for(int i=0;i<=9;++i)
		for(int j=0;j<=9;++j)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		
		ans=0;
		if(a[1]!=0){
			if(f[0][a[1]]>100){
				g[x][y]=-1;
				continue;
			}
			ans+=f[0][a[1]]-1;
		}
		for(int i=2;i<=n;++i){
			if(f[a[i-1]][a[i]]>100){
				g[x][y]=-1;
				goto lll;
			}
			ans+=f[a[i-1]][a[i]]-1;
		}
		g[x][y]=ans;lll:;lllll:;
	} 
	for(int i=0;i<=9;++i){
		for(int j=0;j<=9;++j)printf("%d ",g[i][j]); //[] 
		puts("");  //\n//  putchar // 32//??
	}
}