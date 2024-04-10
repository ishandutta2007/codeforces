#include <stdio.h>
#include <vector>
int direX[5]={1,0,-1,0},direY[5]={0,1,0,-1};
int check[1010][1010][5][5];
std::pair<int,int> S,T;
char x[1010][1010];

int func(int s, int t, int count, int type)
{
	if(count>3) return 0;
	if(s==T.first&&t==T.second) return 1;
	if(check[s][t][count][type]!=-1) return check[s][t][count][type];
	
	for(int i=0;i<4;i++)
	{
		int ns = s+direX[i];
		int nt = t+direY[i];
		if(x[ns][nt]=='.'||x[ns][nt]=='T')
		{
			int k;
			if(i==type) k = func(ns,nt,count,i);
			else k = func(ns,nt,count+1,i);
			if(k==1) return check[s][t][count][type] = 1;
		}
	}
	return check[s][t][count][type] = 0;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) for(int k=0;k<=4;k++) for(int l=0;l<=4;l++) check[i][j][k][l] = -1;
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='S') S = std::make_pair(i,j);
			if(x[i][j]=='T') T = std::make_pair(i,j);
		}
	}
	int s = func(S.first,S.second,0,4);
	printf("%s",s==1?"YES":"NO");
}