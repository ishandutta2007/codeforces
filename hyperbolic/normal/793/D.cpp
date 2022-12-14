#include <stdio.h>
#include <vector>
#define MAX 12345678

int b;
int check[110][110][3][110];
std::vector<int> V[110];
int cost[110][110];

int func(int L, int R, int type, int count)
{
	if(count==b) return 0;
	if(check[L][R][type][count]!=-1) return check[L][R][type][count];
	
	int ind;
	if(type==1) ind = L;
	else ind = R;
	
	int ans = MAX;
	for(int i=0;i<V[ind].size();i++)
	{
		int nind = V[ind][i];
		if(L<nind&&nind<R)
		{
			int s = func(L,nind,2,count+1) + cost[ind][nind];
			int t = func(nind,R,1,count+1) + cost[ind][nind];
			ans = ans<s?ans:s;
			ans = ans<t?ans:t;
		}
	}
	return check[L][R][type][count] = ans;
}
int main()
{
	int a,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) cost[i][j] = MAX;
	for(int i=0;i<=a+1;i++) for(int j=0;j<=a+1;j++) for(int k=1;k<=2;k++) for(int l=1;l<=b;l++) check[i][j][k][l] = -1;
	
	for(int i=1;i<=c;i++)
	{
		int d,e,f;
		scanf("%d%d%d",&d,&e,&f);
		cost[d][e] = cost[d][e]<f?cost[d][e]:f;
		//cost[e][d] = cost[e][d]<f?cost[e][d]:f;
	}
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) if(cost[i][j]<MAX) V[i].push_back(j);
	
	int ans = MAX;
	for(int i=1;i<=a;i++)
	{
		int s = func(0,i,2,1);
		int t = func(i,a+1,1,1);
		ans = ans<s?ans:s;
		ans = ans<t?ans:t;
	}
	if(ans<MAX) printf("%d",ans);
	else printf("-1");
}