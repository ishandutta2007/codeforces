#include <stdio.h>
#include <vector>
#include <algorithm>
#define MOD 1000000007
std::vector<int> row[100010],col[100010];
struct Point{
	int x0;
	int y0;
}x[100010],y[100010];
bool cmp1(Point a, Point b)
{
	return a.x0<b.x0;
}
bool cmp2(Point a, Point b)
{
	return a.y0<b.y0;
}

int checkRow[100010],checkCol[100010];
int checkPoint[100010];
std::pair<int,int> p;
void func_col(int);
void func_row(int k)
{
	for(int i=0;i<row[k].size();i++)
	{
		if(checkCol[x[row[k][i]].y0]==0)
		{
			checkCol[x[row[k][i]].y0] = 1;
			p.first++;
			if(checkPoint[row[k][i]]==0)
			{
				checkPoint[row[k][i]] = 1;
				p.second++;
			}
			func_col(x[row[k][i]].y0);
		}
		else if(checkPoint[row[k][i]]==0)
		{
			checkPoint[row[k][i]] = 1;
			p.second++;
		}
	}
}
void func_col(int k)
{
	for(int i=0;i<col[k].size();i++)
	{
		if(checkRow[x[col[k][i]].x0]==0)
		{
			checkRow[x[col[k][i]].x0] = 1;
			p.first++;
			if(checkPoint[col[k][i]]==0)
			{
				checkPoint[col[k][i]] = 1;
				p.second++;
			}
			func_row(x[col[k][i]].x0);
		}
		else if(checkPoint[col[k][i]]==0)
		{
			checkPoint[col[k][i]] = 1;
			p.second++;
		}
	}
}
long long int pow(int k)
{
	long long int ans = 1;
	for(int i=1;i<=k;i++)
	{
		ans*=2;
		ans%=MOD;
	}
	return ans;
}
int main()
{
	int a,s;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d%d",&x[i].x0,&x[i].y0);
	std::sort(x+1,x+a+1,cmp1);
	s = 1, y[1].x0 = 1;
	for(int i=2;i<=a;i++)
	{
		if(x[i].x0!=x[i-1].x0) s++;
		y[i].x0 = s;
	}
	for(int i=1;i<=a;i++) x[i].x0 = y[i].x0;
	std::sort(x+1,x+a+1,cmp2);
	s = 1, y[1].y0 = 1;
	for(int i=2;i<=a;i++)
	{
		if(x[i].y0!=x[i-1].y0) s++;
		y[i].y0 = s;
	}
	for(int i=1;i<=a;i++) x[i].y0 = y[i].y0;
	for(int i=1;i<=a;i++)
	{
		row[x[i].x0].push_back(i);
		col[x[i].y0].push_back(i);
	}
	long long int ans = 1;
	for(int i=1;i<=x[a].y0;i++)
	{
		p = std::make_pair(1,0);
		if(checkCol[i]==0)
		{
			checkCol[i] = 1;
			func_col(i);
		}
		if(p.first>p.second)
		{
			ans*=(pow(p.first)-1);
			ans%=MOD;
		}
		else
		{
			ans*=pow(p.first);
			ans%=MOD;
		}
	}
	printf("%I64d",ans);
}