#include<bits/stdc++.h>
using namespace std;
string G[1010];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++)
			cin>>G[i];
		if(m%2)
		{
			puts("YES");
			for(int i=0;i<(m+1)/2;i++)
				cout<<"1 2 ";
		}
		else
		{
			bool done=0;
			for(int i=0;i<n&&!done;i++)
				for(int j=i+1;j<n&&!done;j++)
					if(G[i][j]==G[j][i])
					{
						puts("YES");
						for(int l=0;l<m/2;l++)
							cout<<i+1<<" "<<j+1<<" ";
						cout<<i+1;
						done=true;
						break;
					}
			if(!done)
			{
				if(n==2)
				{
					cout<<"NO";
				}
				else
				{
					puts("YES");
					if(G[0][1]==G[2][0])
					{
						if(m%4==0)
						{
							for(int i=0;i<m/4;i++)
								cout<<"1 2 ";
							for(int i=0;i<m/4;i++)
								cout<<"1 3 ";
							cout<<1;
						}
						else
						{
							for(int i=0;i<=m/4;i++)
								cout<<"2 1 ";
							for(int i=0;i<m/4;i++)
								cout<<"3 1 ";
							cout<<3;
						}
					}
					else if(G[1][2]==G[0][1])
					{
						if(m%4==0)
						{
							for(int i=0;i<m/4;i++)
								cout<<"2 3 ";
							for(int i=0;i<m/4;i++)
								cout<<"2 1 ";
							cout<<2;
						}
						else
						{
							for(int i=0;i<=m/4;i++)
								cout<<"1 2 ";
							for(int i=0;i<m/4;i++)
								cout<<"3 2 ";
							cout<<3;
						}
					}
					else if(G[2][0]==G[1][2])
					{
						if(m%4==0)
						{
							for(int i=0;i<m/4;i++)
								cout<<"3 1 ";
							for(int i=0;i<m/4;i++)
								cout<<"3 2 ";
							cout<<3;
						}
						else
						{
							for(int i=0;i<=m/4;i++)
								cout<<"2 3 ";
							for(int i=0;i<m/4;i++)
								cout<<"1 3 ";
							cout<<1;
						}
					}
				//	else	cout<<"NO";
				}
			}
		}
		puts("");
	}
}