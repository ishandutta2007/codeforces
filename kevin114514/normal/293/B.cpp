#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
int premask[15][15],usemask[15][15];
int colormask;
int N,M,K;
int color[1010][1010];
int dfs(int x,int y)
{
	if(x==N)
		return 1;
	if(y==M)
		return dfs(x+1,0);
	usemask[x][y]=0;
	if(x)
		usemask[x][y]|=usemask[x-1][y];
	if(y)
		usemask[x][y]|=usemask[x][y-1];
	if(color[x][y])
		usemask[x][y]|=(1<<color[x][y]);
	if(color[x][y])
	{
		return dfs(x,y+1);
	}
	//unused
	int ans=0;
	for(int i=1;i<=K;i++)
		if(!((1<<i)&colormask))
		{
			usemask[x][y]^=(1<<i);
			colormask^=(1<<i);
			ans+=(K-__builtin_popcount(colormask)+1)*dfs(x,y+1)%MOD;
			usemask[x][y]^=(1<<i);
			colormask^=(1<<i);
			break;
		}
	//used
	int notuse=premask[x][y];
	if(x)
		notuse|=usemask[x-1][y];
	if(y)
		notuse|=usemask[x][y-1];
	for(int i=1;i<=K;i++)
		if(!((1<<i)&notuse)&&((1<<i)&colormask))
		{
			usemask[x][y]^=(1<<i);
			ans+=dfs(x,y+1);
			usemask[x][y]^=(1<<i);
		}
//	cout<<x<<" "<<y<<" "<<ans<<endl;
	return ans%MOD;
}
signed main()
{
	cin>>N>>M>>K;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin>>color[i][j];
	if(N+M-1>K)
	{
		puts("0");
		return 0;
	}
	bool have0=false;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(color[i][j])
			{
				for(int ii=0;ii<N;ii++)
					for(int jj=0;jj<M;jj++)
						if((ii<=i&&jj<=j)||(ii>=i&&jj>=j))
						{
							if(color[i][j]==color[ii][jj]&&(ii!=i||jj!=j))
							{
								puts("0");
								return 0;
							}
							premask[ii][jj]|=(1<<color[i][j]);
						}
				colormask|=(1<<color[i][j]);
			}
			else	have0=true;
	if(!have0)
		cout<<"1\n";
	else	cout<<dfs(0,0)<<endl;
	return 0;
}