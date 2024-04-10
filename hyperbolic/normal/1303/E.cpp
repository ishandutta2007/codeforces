#include <stdio.h>
#include <string.h>

struct str{
	short first;
	short second;
}check[401][401][401];
bool operator<(str a, str b)
{
	if(a.second==b.second) return a.first<b.first;
	return a.second<b.second;
}

int a,b;
char x[100010],y[100010];
str func(int k, int s, int t)
{
	if(k>a) return {s,t};
	if(check[k][s][t].first!=-1) return check[k][s][t];
	
	str p1,p2,p3;
	if(x[k]==y[s]) p1 = func(k+1,s+1,t);
	else p1 = {0,0};
	if(x[k]==y[t]) p2 = func(k+1,s,t+1);
	else p2 = {0,0};
	p3 = func(k+1,s,t);
	return check[k][s][t] = p1<p2?p2<p3?p3:p2:p1<p3?p3:p1;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",x+1,y+1);
		a = strlen(x+1), b = strlen(y+1);
		y[b+1] = 0;
		
		for(int i=1;i<=a;i++) for(int j=0;j<=b+1;j++) for(int k=0;k<=b+1;k++) check[i][j][k] = {-1,-1};
		for(int i=1;i<=b;i++)
		{
			str A = func(1,1,i);
			if(A.first>=i&&A.second>b)
			{
				printf("YES\n");
				goto u;
			}
		}
		printf("NO\n");
		u:;
	}
}