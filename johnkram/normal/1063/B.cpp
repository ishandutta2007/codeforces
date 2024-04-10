#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,-1,0,1},dy[]={-1,0,1,0};
int n,m,r,c,x,y,i,j,k,ans,d[2005][2005];
char s[2005][2005];
deque<int> qx,qy;
int main()
{
	scanf("%d%d%d%d%d%d",&n,&m,&r,&c,&x,&y);
	for(i=1;i<=n;i++)scanf("%s",s[i]+1);
	qx.push_back(r);
	qy.push_back(c);
	memset(d,127,sizeof(d));
	d[r][c]=0;
	while(!qx.empty())
	{
		i=qx.front();
		j=qy.front();
		qx.pop_front();
		qy.pop_front();
		for(k=0;k<4;k++)if(i+dx[k]&&j+dy[k]&&i+dx[k]<=n&&j+dy[k]<=m&&s[i+dx[k]][j+dy[k]]=='.'&&d[i+dx[k]][j+dy[k]]>d[i][j]+(!k))
		{
			d[i+dx[k]][j+dy[k]]=d[i][j]+!k;
			if(k)
			{
				qx.push_front(i+dx[k]);
				qy.push_front(j+dy[k]);
			}
			else
			{
				qx.push_back(i+dx[k]);
				qy.push_back(j+dy[k]);
			}
		}
	}
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)if(d[i][j]<=x&&d[i][j]+j<=y+c)ans++;
	cout<<ans<<endl;
	return 0;
}