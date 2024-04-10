#include<bits/stdc++.h>

#define lli long long int
using namespace std;

int visit[251][251];
pair<pair<int,int>,lli> pair1;
string c[251];
int main()
{
	int n,m;
	cin>>n>>m;
	lli q,allowed;
	cin>>q>>allowed;
	
	for(int i=0;i<n;i++)
		cin>>c[i];
		
	int dx[]={1,-1,0,0};
	int dy[]={0,0,1,-1};
	

	
	lli total[n][m];
	
	vector<pair<int,int>> v;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			total[i][j]=0;
	
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(c[i][j]=='*' || c[i][j]=='.')
				continue;
			
			for(auto p :v)
			{
				visit[p.first][p.second]=0;
			}
			
			v.clear();
			
			queue<pair<pair<int,int>,lli>> q1;
			q1.push({{i,j},q*(c[i][j]-'A'+1)});
			
			while(!q1.empty())
			{
				pair1=q1.front();
				q1.pop();
				v.push_back({pair1.first.first,pair1.first.second});
				
				if(visit[pair1.first.first][pair1.first.second])
					continue;
				
				visit[pair1.first.first][pair1.first.second]++;
				total[pair1.first.first][pair1.first.second]+=pair1.second;
				
				for(int k=0;k<4;k++)
				{
					int nx=pair1.first.first+dx[k];
					int ny=pair1.first.second+dy[k];
					
					if(nx>=0 && ny>=0 && nx<n && ny<m && visit[nx][ny]==0 && pair1.second>=2 && c[nx][ny]!='*')
						q1.push({{nx,ny},pair1.second/2});
				}
			}
		}
		
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(total[i][j]>allowed)
				ans++;
		}
	}
	
	cout<<ans;	
	return 0;
}