#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXL=5005,SIGMA=26;

int l;
char s[MAXL];
int vis[MAXL][SIGMA],cnt[SIGMA];

void work(int p)
{
	for (int i=1;i<l;i++)
		vis[i][s[(i+p)%l]]++;
}

int main()
{
	scanf("%s",s);
	l=strlen(s);
	for (int i=0;i<l;i++)
		s[i]-='a';
	for (int i=0;i<SIGMA;i++)
	{
		memset(vis,0,sizeof(vis));
		for (int j=0;j<l;j++)
			if (s[j]==i)
				work(j);
		int &mx=cnt[i];
		for (int j=1;j<l;j++)
		{
			int ret=0;
			for (int k=0;k<SIGMA;k++)
				if (vis[j][k]==1)
					ret++;
			mx=max(mx,ret);
		}
	}
	int ans=0;
	for (int i=0;i<SIGMA;i++)
		ans+=cnt[i];
	printf("%.9f",(double)ans/l);
	return 0;
}