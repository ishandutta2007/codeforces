#include <stdio.h>
#include <vector>
#include <string.h>

int a;
int count[100010][30];
std::vector<char> y[100010];
int lenL[100010],lenR[100010];

void func(int k)
{
	if(k>a) return;
	
	int t = 1;
	for(int j=1;j<y[k].size();j++)
	{
		if(y[k][j]==y[k][j-1]) t++;
		else
		{
			count[k][y[k][j-1]-'a'] = count[k][y[k][j-1]-'a']>t?count[k][y[k][j-1]-'a']:t;
			t = 1;
		}
	}
	count[k][y[k].back()-'a'] = count[k][y[k].back()-'a']>t?count[k][y[k].back()-'a']:t;
	
	if(lenL[k]==y[k].size())
	{
		for(int i=0;i<26;i++) if(count[k-1][i]>0) count[k][i] = count[k][i]>1?count[k][i]:1;
		int c = y[k][0]-'a';
		count[k][c] = count[k][c]>(count[k-1][c]) + y[k].size()*(count[k-1][c]+1)?count[k][c]:(count[k-1][c]) + y[k].size()*(count[k-1][c]+1);
	}
	else
	{
		for(int i=0;i<26;i++)
		{
			if(count[k-1][i]>0)
			{
				int c = 1;
				if(i==y[k][0]-'a') c += lenL[k];
				if(i==y[k].back()-'a') c += lenR[k];
				count[k][i] = count[k][i]>c?count[k][i]:c;
			}
		}
	}
	func(k+1);
}

char x[100010];
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		int b = strlen(x+1);
		for(int j=1;j<=b;j++) y[i].push_back(x[j]);
		for(int j=1;j<=b;j++)
		{
			if(x[j]!=x[1])
			{
				lenL[i] = j-1;
				goto u1;
			}
		}
		lenL[i] = b;
		u1:;
		for(int j=b;j>=1;j--)
		{
			if(x[j]!=x[b])
			{
				lenR[i] = b-j;
				goto u2;
			}
		}
		lenR[i] = b;
		u2:;
	}
	
	int t = 1;
	for(int j=1;j<y[1].size();j++)
	{
		if(y[1][j]==y[1][j-1]) t++;
		else
		{
			count[1][y[1][j-1]-'a'] = count[1][y[1][j-1]-'a']>t?count[1][y[1][j-1]-'a']:t;
			t = 1;
		}
	}
	count[1][y[1].back()-'a'] = count[1][y[1].back()-'a']>t?count[1][y[1].back()-'a']:t;
	
	func(2);
	int max = 0;
	for(int i=0;i<26;i++) max = max>count[a][i]?max:count[a][i];
	printf("%d",max);
}