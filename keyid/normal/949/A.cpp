#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define mp make_pair
#define fi first
#define sc second
#define pb push_back

const int MAXL=200005;

char s[MAXL];
int nxt[MAXL];
bool vis[MAXL];
vector <int> p[2];

int main()
{
	scanf("%s",s);
	int l=strlen(s);
	for (int i=0;i<l;i++)
		s[i]-='0';
	for (int i=0;i<l;i++)
		nxt[i]=l;
	for (int i=0;i<l;i++)
		if (s[i]==0)
		{
			if (!p[1].empty())
			{
				int k=p[1].back();
				p[1].pop_back();
				nxt[k]=i;
			}
			p[0].pb(i);
		}
		else
		{
			if (p[0].empty())
			{
				puts("-1");
				return 0;
			}
			int k=p[0].back();
			p[0].pop_back();
			nxt[k]=i;
			p[1].pb(i);
		}
	if (!p[1].empty())
	{
		puts("-1");
		return 0;
	}
	int cnt=0;
	for (int i=0;i<l;i++)
		if (!vis[i])
		{
			cnt++;
			for (int j=i;j<l;j=nxt[j])
				vis[j]=true;
		}
	printf("%d\n",cnt);
	memset(vis,0,sizeof(vis));
	for (int i=0;i<l;i++)
		if (!vis[i])
		{
			cnt=0;
			for (int j=i;j<l;j=nxt[j])
			{
				vis[j]=true;
				cnt++;
			}
			printf("%d",cnt);
			for (int j=i;j<l;j=nxt[j])
				printf(" %d",j+1);
			puts("");
		}
	return 0;
}