#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef long long int ll;
using namespace std;
int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n,m;
		cin>>n>>m;
		vector<int> gra[n];
		int grp[n]={0};
		int a,b;
		FOR(i,0,m)
		{
			cin>>a>>b;
			gra[a-1].push_back(b-1);
			gra[b-1].push_back(a-1);
		}
		FOR(i,0,n)
		{
			sort(gra[i].begin(),gra[i].end());
		}
		int cnt=0;
		bool f=1;
		FOR(i,0,n)
		{
			if(grp[i]==0)
			{
				cnt++;
				grp[i]=cnt;
				int p=0;
				int s=gra[i].size();
				FOR(j,0,n)
				{
					if(j==i)
						continue;
					if(p<s)
						if(gra[i][p]==j)
							{
								p++;
								continue;
							}
					
					
					grp[j]=cnt;
					if(s!=gra[j].size())
					{
						f=0;
						break;
					}
					FOR(k,0,s)
					{
						if(gra[i][k]!=gra[j][k])
						{
							f=0;
							break;
						}
					}
					if(f==0)
						break;
				}
			}
			if(f==0)
				break;
		}
		if(f && cnt==3)
		{
			FOR(i,0,n)
			cout<<grp[i]<<' ';
		}
		else
		cout<<-1;
	}
	return 0;
}