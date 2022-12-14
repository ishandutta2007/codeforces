#include <stdio.h>
#include <set>
#include <stack>
#define MOD 2520

std::set<int> S;
std::stack< std::pair<int,int> > St;
std::pair<int,int> next[1010][2530];
int check[1010][2530], check2[1010][2530];
int x[1010],y[1010];

int func(int s, int t)
{
	if(check[s][t]!=-1) return check[s][t];
	else if(check2[s][t] == 1)
	{
		S.clear();
		while(!St.empty())
		{
			int s0 = St.top().first, t0 = St.top().second;
			S.insert(s0);
			St.pop();
			
			if(s==s0 && t == t0) break;
		}
		
		int count = 0;
		for(std::set<int> ::iterator it = S.begin(); it!=S.end();it++) count++;
		return check[s][t] = count;
	}
	else
	{
		check2[s][t] = 1;
		St.push(std::make_pair(s,t));
		return check[s][t] = func(next[s][t].first,next[s][t].second);
	}
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) x[i] = ((x[i]%MOD)+2*MOD)%MOD;
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&y[i]);
		for(int j=0;j<y[i];j++)
		{
			int b;
			scanf("%d",&b);
			for(int k=0;k<MOD;k++) if((k+x[i])%y[i]==j) next[i][k] = (std::make_pair(b,(k+x[i])%MOD));
		}
	}
	for(int i=1;i<=a;i++) for(int k=0;k<=MOD;k++) check[i][k] = -1;
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		d = ((d%MOD)+2*MOD)%MOD;
		printf("%d\n",func(c,d));
	}
}