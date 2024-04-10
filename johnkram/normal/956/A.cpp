#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,f[105];
char c[55][55];
int get(int x)
{
	if(f[x]==x)return x;
	return f[x]=get(f[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%s",c[i]);
	for(i=0;i<n+m;i++)f[i]=i;
	for(i=0;i<n;i++)for(j=0;j<m;j++)if(c[i][j]=='#')f[get(i)]=get(j+n);
	for(i=0;i<n;i++)for(j=0;j<m;j++)if(c[i][j]!='#'&&get(i)==get(j+n))goto xxx;
	puts("Yes");
	return 0;
	xxx:puts("No");
	return 0;
}