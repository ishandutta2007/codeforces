#include <stdio.h>
#include <vector>

int abs(int k)
{
	return k>0?k:-k;
}

char ans[4010][4010];
std::vector< std::pair<int,int> > event[4000010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			int c;
			scanf("%d",&c);
			event[c].push_back(std::make_pair(i-j+2000,i+j));
		}
	}
	
	for(int i=1;i<=4000;i++) for(int j=1;j<=4000;j++) if((i+j)%2==0) ans[i][j] = 'G';
	int L = 1, R = 4000, U = 1, D = 4000;
	
	for(int i=4000000;i>=1;i--)
	{
		int L2 = L, R2 = R ,U2 = U, D2 = D;
		for(int j=0;j<event[i].size();j++)
		{
			int s = event[i][j].first, t = event[i][j].second;
			if(U<=s&&s<=D&&L<=t&&t<=R)
			{
				L2 = L2>t-b?L2:t-b;
				R2 = R2<t+b?R2:t+b;
				U2 = U2>s-b?U2:s-b;
				D2 = D2<s+b?D2:s+b;
			}
		}
		
		for(int j=0;j<event[i].size();j++)
		{
			if(U<=event[i][j].first&&event[i][j].first<=D&&L<=event[i][j].second&&event[i][j].second<=R)
			{
				for(int k=0;k<event[i].size();k++)
				{
					if(U<=event[i][k].first&&event[i][k].first<=D&&L<=event[i][k].second&&event[i][k].second<=R)
					{
						int d1 = abs(event[i][j].first-event[i][k].first);
						int d2 = abs(event[i][j].second-event[i][k].second);
						int dist = d1>d2?d1:d2;
						if(dist>b)
						{
							ans[event[i][j].first][event[i][j].second] = 'D';
							goto u;
						}
					}
				}
				ans[event[i][j].first][event[i][j].second] = 'M';
				u:;
			}
		}
		
		L = L2, R = R2, U = U2, D = D2;
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++) printf("%c",ans[i-j+2000][i+j]);
		printf("\n");
	}
}