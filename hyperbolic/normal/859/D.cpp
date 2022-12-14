#include <stdio.h>
int x[700][700],a,b;
int level[700][700];
double sum[700][700];
double check2[700][700];
double func(int s, int t)
{
	if(t==a) return 1;
	if(check2[s][t]!=0) return check2[s][t];
	//s level t  
	int k = level[s][t+1],k2;
	if(k%2==1) k2 = k-1;
	else k2 = k+1;
	double sum = 0;
	for(int i=1;i<=b;i++) if(level[i][t+1]==k2) sum+= func(i,t+1)*x[s][i]/100;
	return check2[s][t] = sum*func(s,t+1);
}
double check[700][700];
double getAns(int s, int t)
{
	double ans = 0;
	if(t==a) return 0;
	if(check[s][t]!=0) return check[s][t];
	for(int i=1;i<=b;i++)
	{
		if(level[i][t]==s)
		{
			double m = sum[i][t];
			for(int j=t+1;j<a;j++) m+=getAns(level[i][j]^1,j);
			ans = ans>m?ans:m;
		}
	}
	return check[s][t] = ans;
}
int main()
{
	scanf("%d",&a);
	b = (1<<a);
	for(int i=1;i<=b;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
	for(int i=1;i<=b;i++) level[i][a] = i+b-1;
	for(int j=a-1;j>=0;j--) for(int i=1;i<=b;i++) level[i][j] = level[i][j+1]/2;
	for(int j=a-1;j>=0;j--) for(int i=1;i<=b;i++) sum[i][j]=sum[i][j+1]+func(i,j)*(1<<(a-j-1));
	printf("%.12lf",getAns(1,0));
}