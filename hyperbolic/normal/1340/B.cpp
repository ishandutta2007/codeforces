#include <stdio.h>
#include <vector>

std::vector<int> V[11],V2[2010];
std::vector<int> ans;
int control = 0, a;

char x[2010][2010];
int y[11][11];
int check[2010][2010];
int func(int s, int t)
{
	if(control==1) return -1;
	if(t<0) return -1;
	if(s>a)
	{
		if(t==0)
		{
			control = 1;
			return 1;
		}
		else return -1;
	}
	if(check[s][t]) return -1;
	
	for(int i=9;i>=0;i--)
	{
		int S = -1;
		for(int j=0;j<V2[s].size();j++)
		{
			if(y[i][V2[s][j]]==1) goto u;
		}
		
		S = func(s+1,t-(7-V[i].size()-V2[s].size()));
		if(S==1)
		{
			ans.push_back(i);
			return check[s][t] = 1;
		}
		u:;
	}
	check[s][t] = 1;
	return -1;
}

int main()
{
	V[0].push_back(4);
	V[1].push_back(1), V[1].push_back(2), V[1].push_back(4), V[1].push_back(5), V[1].push_back(7);
	V[2].push_back(2), V[2].push_back(6);
	V[3].push_back(2), V[3].push_back(5);
	V[4].push_back(1), V[4].push_back(5), V[4].push_back(7);
	V[5].push_back(3), V[5].push_back(5);
	V[6].push_back(3);
	V[7].push_back(2), V[7].push_back(4), V[7].push_back(5), V[7].push_back(7);
	V[9].push_back(5);
	for(int j=0;j<=9;j++) for(int k=0;k<V[j].size();k++) y[j][V[j][k]] = 1;
	
	int b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x[i]+1);
		for(int j=1;j<=7;j++) if(x[i][j]=='1') V2[i].push_back(j);
	}
	
	func(1,b);
	if(ans.size()==0) printf("-1");
	else for(int i=ans.size()-1;i>=0;i--) printf("%d",ans[i]);
}