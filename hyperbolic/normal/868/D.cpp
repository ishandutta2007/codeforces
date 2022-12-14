#include <stdio.h>
#include <string.h>
#include <vector>
#define MAX 11

int l[110];
char x[110][110];
int check[210][MAX+1][1<<(MAX)];
int ans[210];
std::vector<char> left[210],right[210];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x[i]+1);
		l[i] = strlen(x[i]+1);
		for(int j=1;j<=MAX&&j<=l[i];j++)
		{
			int sum = 0;
			for(int k=1;k<=j;k++)
			{
				sum*=2;
				sum+=x[i][k]-'0';
			}
			check[i][j][sum] = 1;
			for(int k=j+1;k<=l[i];k++)
			{
				sum*=2;
				sum+=x[i][k]-'0';
				sum%=(1<<j);
				check[i][j][sum] = 1;
			}
		}
		for(int j=1;j<=MAX&&j<=l[i];j++)
		{
			for(int k=0;k<(1<<j);k++)
			{
				if(check[i][j][k]==0)
				{
					goto u;
				}
			}
			ans[i] = j;
		}
		u:;
	}
	for(int i=1;i<=a;i++)
	{
		int m = l[i]<MAX?l[i]:MAX;
		for(int j=1;j<=m;j++) left[i].push_back(x[i][j]);
		for(int j=l[i]-m+1;j<=l[i];j++) right[i].push_back(x[i][j]);
	}
	
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		ans[a+i] = ans[c]>ans[d]?ans[c]:ans[d];
		
		if(left[c].size()<MAX)
		{
			for(int j=0;j<left[c].size();j++) left[a+i].push_back(left[c][j]);
			int m = left[d].size()<MAX-left[c].size()?left[d].size():MAX-left[c].size();
			for(int j=0;j<m;j++) left[a+i].push_back(left[d][j]);
		}
		else left[a+i] = left[c];
		if(right[d].size()<MAX)
		{
			int m = right[c].size()<MAX-right[d].size()?right[c].size():MAX-right[d].size();
			for(int j=0;j<m;j++) right[a+i].push_back(right[c][right[c].size()-m+j]);
			for(int j=0;j<right[d].size();j++) right[a+i].push_back(right[d][j]);
		}
		else right[a+i] = right[d];
		
		for(int j=ans[a+i]+1;j<=MAX;j++) for(int k=0;k<(1<<j);k++) check[a+i][j][k] = (check[c][j][k]|check[d][j][k]);
		std::vector<char> V = right[c];
		for(int j=0;j<left[d].size();j++) V.push_back(left[d][j]);
		for(int j=ans[a+i]+1;j<=MAX;j++)
		{
			if(j>V.size()) break;
			int sum = 0;
			for(int k=1;k<=j;k++)
			{
				sum*=2;
				sum+=V[k-1]-'0';
			}
			check[a+i][j][sum] = 1;
			for(int k=j+1;k<=V.size();k++)
			{
				sum*=2;
				sum+=V[k-1]-'0';
				sum%=(1<<j);
				check[a+i][j][sum] = 1;
			}
		}
		for(int j=ans[a+i]+1;j<=MAX;j++)
		{
			for(int k=0;k<(1<<j);k++)
			{
				if(check[a+i][j][k]==0)
				{
					goto v;
				}
			}
			ans[a+i] = j;
		}
		v:;
	}
	for(int i=1;i<=b;i++) printf("%d\n",ans[a+i]);
}