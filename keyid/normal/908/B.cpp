#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=55,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

struct Point
{
	int x,y;
};

int n,m,id[4];
char s[MAXN][MAXN],ins[105];

bool check()
{
	queue <Point> q;
	int x,y;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (s[i][j]=='S')
			{
				x=i;
				y=j;
			}
	int l=strlen(ins);
	for (int i=0;i<l;i++)
	{
		int dir=id[ins[i]-'0'];
		x+=dx[dir];
		y+=dy[dir];
		if (x<0||x>=n||y<0||y>=m||s[x][y]=='#')
			return false;
		if (s[x][y]=='E')
			return true;
	}
	return false;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
		scanf("%s",s[i]);
	scanf("%s",ins);
	for (int i=0;i<4;i++)
		id[i]=i;
	int ans=0;
	do
	{
		if (check())
			ans++;
	}while (next_permutation(id,id+4));
	printf("%d",ans);
	return 0;
}