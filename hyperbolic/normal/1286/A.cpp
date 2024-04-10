#include <stdio.h>

int a;
int count[3];
int x[110];
int check[110][110][110][4];

int func(int k, int s, int t, int prev)
{
	if(k>a) return 0;
	if(check[k][s][t][prev]!=-1) return check[k][s][t][prev];
	
	if(x[k]>0)
	{
		if(prev==2) return check[k][s][t][prev] = func(k+1,s,t,x[k]%2);
		if((x[k]-prev+1234)%2==1) return check[k][s][t][prev] = func(k+1,s,t,x[k]%2)+1;
		else return check[k][s][t][prev] = func(k+1,s,t,x[k]%2);
	}
	else
	{
		int s1 = 1234, s2 = 1234;
		if(s>0)
		{
			if(prev!=2 && prev==1) s1 = func(k+1,s-1,t,0)+1;
			else s1 = func(k+1,s-1,t,0);
		}
		if(t>0)
		{
			if(prev!=2 && prev==0) s2 = func(k+1,s,t-1,1)+1;
			else s2 = func(k+1,s,t-1,1);
		}
		return check[k][s][t][prev] = s1<s2?s1:s2;
	}
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) for(int j=0;j<=a;j++) for(int k=0;k<=a;k++) for(int l=0;l<=2;l++) check[i][j][k][l] = -1;
	
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=a;i++) count[i%2]++;
	for(int i=1;i<=a;i++) if(x[i]>0) count[x[i]%2]--;
	
	printf("%d",func(1,count[0],count[1],2));
}