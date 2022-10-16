#include<bits/stdc++.h>
using namespace std;
int d[102][100003];
queue<int> qu;
int n;
int len[102];
void BFS()
{
	while(!qu.empty())
	{
		int x=qu.front();
		qu.pop();
		int y=qu.front();
		qu.pop();
		//UP
		if(x>1)
		{
			int to_y=min(y,len[x-1]);
			if(d[x-1][to_y]==0)
			{
				d[x-1][to_y]=d[x][y]+1;
				qu.push(x-1);
				qu.push(to_y);
			}
		}
		//DOWN
		if(x<n)
		{
			int to_y=min(y,len[x+1]);
			if(d[x+1][to_y]==0)
			{
				d[x+1][to_y]=d[x][y]+1;
				qu.push(x+1);
				qu.push(to_y);
			}
		}
		//LEFT
		if(y>1)
		{
			if(d[x][y-1]==0)
			{
				d[x][y-1]=d[x][y]+1;
				qu.push(x);
				qu.push(y-1);
			}
		}
		//RIGHT
		if(y<len[x])
		{
			if(d[x][y+1]==0)
			{
				d[x][y+1]=d[x][y]+1;
				qu.push(x);
				qu.push(y+1);
			}
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>len[i];
		len[i]++;
	}
	int r1,c1,r2,c2;
	cin>>r1>>c1>>r2>>c2;
	d[r1][c1]=1;
	qu.push(r1);
	qu.push(c1);
	BFS();
	cout<<d[r2][c2]-1;
	return 0;
}