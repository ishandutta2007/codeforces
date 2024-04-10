#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,lx,rx,ly,ry;
char s[205][205];
int main()
{
	scanf("%d%d",&n,&m);
	lx=n;
	ly=m;
	rx=ry=1;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(j=1;j<=m;j++)if(s[i][j]=='B')
		{
			lx=min(lx,i);
			rx=max(rx,i);
			ly=min(ly,j);
			ry=max(ry,j);
		}
	}
	cout<<(lx+rx>>1)<<' '<<(ly+ry>>1)<<endl;
	return 0;
}