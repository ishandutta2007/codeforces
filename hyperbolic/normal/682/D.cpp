#include <stdio.h>
char x[1010],y[1010];
int check1[1010][1010][11];
int check2[1010][1010][11];
int a,b,c;
int func2(int s, int t, int k);
int func1(int s, int t , int k)
{
	if(k>c) return 0;
	if(t>b) return 0;
	if(s>a) return 0;
	if(check1[s][t][k]!=-1) return check1[s][t][k];
	//    
	int s1 = func1(s+1,t,k);
	int s2 = func1(s,t+1,k);
	int s3;
	if(x[s]==y[t]) s3 = func2(s+1,t+1,k)+1;
	else s3 = 0;
	return check1[s][t][k] = s1>s2?s3>s1?s3:s1:s3>s2?s3:s2;
}
int func2(int s, int t, int k)
{
	if(s>a) return 0;
	if(t>b) return 0;
	if(check2[s][t][k]!=-1) return check2[s][t][k];
	int s1;
	if(x[s]==y[t]) s1 = func2(s+1,t+1,k)+1;
	else s1 = 0;
	int s2 = func1(s,t,k+1);
	return check2[s][t][k] = s1>s2?s1:s2;
}
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	scanf("%s%s",x+1,y+1);
	for(int i=0;i<=1001;i++)
	{
		for(int j=0;j<=1001;j++)
		{
			for(int k=0;k<=10;k++)
			{
				check1[i][j][k] = -1;
				check2[i][j][k] = -1;
			}
		}
	}
	printf("%d",func1(1,1,1));
}