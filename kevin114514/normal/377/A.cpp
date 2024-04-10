#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<utility>
#include<algorithm>
#include<functional>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<cstdio>
using namespace std;
string grid[510];
int N,M,K;
vector<int> ans;
bool u[510][510];
const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
void dfs(int x,int y)
{
	if(u[x][y]||grid[x][y]=='#')
		return ;
	u[x][y]=true;
	ans.push_back(x);
	ans.push_back(y);
	for(int d=0;d<4;d++)
		if(x+dx[d]>=0&&x+dx[d]<N&&y+dy[d]>=0&&y+dy[d]<M)
			dfs(x+dx[d],y+dy[d]);
	return ;
}
int main()
{
	cin>>N>>M>>K;
	for(int i=0;i<N;i++)
		cin>>grid[i];
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(grid[i][j]=='.')
			{
				dfs(i,j);
				reverse(ans.begin(),ans.end());
				for(int k=0;k<K;k++)
					grid[ans[k*2+1]][ans[k*2]]='X';
				for(int k=0;k<N;k++)
					puts(grid[k].c_str());
				return 0;
			}
	return 0;
}