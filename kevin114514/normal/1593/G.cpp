#include<bits/stdc++.h>
using namespace std;
int psum[1001000][2];
char buff[1001000];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(psum,0,sizeof(psum));
		scanf("%s",buff);
		int n=strlen(buff);
		for(int i=0;i<n;i++)
			for(int j=0;j<2;j++)
				psum[i+1][j]=psum[i][j]+(i%2==j)*(buff[i]=='['||buff[i]==']');
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			printf("%d\n",(abs((psum[v][0]-psum[u-1][0])-(psum[v][1]-psum[u-1][1]))));
		}
	}
	return 0;
}