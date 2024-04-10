#include <stdio.h>
#include <vector>

struct str{
	int first;
	int second;
	int value;
};
std::vector<str> V;

char x[1010][1010];
int y[1010];
int left[1010][1010],right[1010][1010],up[1010][1010],down[1010][1010];
int ans[1010][1010],check[1010][1010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a;i++)
	{
		int p = 1;
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='.') p = j+1;
			else left[i][j] = p;
		}
	}
	for(int i=1;i<=a;i++)
	{
		int p = b;
		for(int j=b;j>=1;j--)
		{
			if(x[i][j]=='.') p = j-1;
			else right[i][j] = p;
		}
	}
	
	for(int j=1;j<=b;j++)
	{
		int p = 1;
		for(int i=1;i<=a;i++)
		{
			if(x[i][j]=='.') p = i+1;
			else up[i][j] = p;
		}
	}
	
	for(int j=1;j<=b;j++)
	{
		int p = a;
		for(int i=a;i>=1;i--)
		{
			if(x[i][j]=='.') p = i-1;
			else down[i][j] = p;
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='*')
			{
				int s1 = right[i][j] - j;
				int s2 = j - left[i][j];
				int s3 = down[i][j] - i;
				int s4 = i - up[i][j];
				int m = s1;
				m = m<s2?m:s2;
				m = m<s3?m:s3;
				m = m<s4?m:s4;
				ans[i][j] = m;
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b+1;j++) y[j] = 0;
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='*' && ans[i][j]>0)
			{
				y[j-ans[i][j]]++;
				y[j+ans[i][j]+1]--;
			}
		}
		for(int j=1;j<=b;j++) y[j] += y[j-1];
		
		for(int j=1;j<=b;j++) if(x[i][j]=='*'&&y[j]==0) check[i][j]++;
	}
	
	for(int j=1;j<=b;j++)
	{
		for(int i=1;i<=a+1;i++) y[i] = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i][j]=='*' && ans[i][j]>0)
			{
				y[i-ans[i][j]]++;
				y[i+ans[i][j]+1]--;
			}
		}
		for(int i=1;i<=a;i++) y[i] += y[i-1];
		
		for(int i=1;i<=a;i++) if(x[i][j]=='*'&&y[i]==0) check[i][j]++;
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(check[i][j]==2)
			{
				printf("-1");
				return 0;
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(ans[i][j]>0) V.push_back({i,j,ans[i][j]});
		}
	}
	printf("%d\n",V.size());
	for(int i=0;i<V.size();i++) printf("%d %d %d\n",V[i].first,V[i].second,V[i].value);
}