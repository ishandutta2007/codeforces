#include<bits/stdc++.h>
using namespace std;
bool f[1001000];
int psum[1001000];
string grid[1001000];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>grid[i];
		grid[i]='0'+grid[i];
	}
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			if(grid[i+1][j]=='X'&&grid[i][j+1]=='X')
				f[j]=1;
	for(int i=1;i<=m;i++)
		psum[i]=psum[i-1]+f[i];
	int q;
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
//		cout<<psum[y-1]<<" "<<psum[x-1]<<endl;
		if(psum[y-1]==psum[x-1])
			puts("yes");
		else	puts("no");
	}
	return 0;
}