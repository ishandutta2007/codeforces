#include <bits/stdc++.h>
using namespace std;

const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

struct puzzle
{
	int p[2][2];

	bool operator < (const puzzle &b) const
	{
		for (int i=0;i<2;i++)
			for (int j=0;j<2;j++)
				if (p[i][j]!=b.p[i][j])
					return p[i][j]<b.p[i][j];
		return false;
	}
};

set <puzzle> s;
queue <puzzle> q;

int main()
{
	puzzle a,b;
	char str[5];
	for (int i=0;i<2;i++)
	{
		scanf("%s",str);
		for (int j=0;j<2;j++) a.p[i][j]=str[j]-'A';
	}
	for (int i=0;i<2;i++)
	{
		scanf("%s",str);
		for (int j=0;j<2;j++) b.p[i][j]=str[j]-'A';
	}
	s.insert(a);
	q.push(a);
	while (!q.empty())
	{
		puzzle u=q.front();q.pop();
		int x,y;
		for (int i=0;i<2;i++)
			for (int j=0;j<2;j++)
				if (u.p[i][j]>4)
				{
					x=i;
					y=j;
					break;
				}
		for (int i=0;i<4;i++)
		{
			int tx=x+dx[i],ty=y+dy[i];
			if (tx>=0&&tx<2&&ty>=0&&ty<2)
			{
				puzzle c=u;
				swap(c.p[x][y],c.p[tx][ty]);
				if (s.find(c)==s.end())
				{
					s.insert(c);
					q.push(c);
				}
			}
		}
	}
	printf(s.find(b)!=s.end()?"YES":"NO");
	return 0;
}