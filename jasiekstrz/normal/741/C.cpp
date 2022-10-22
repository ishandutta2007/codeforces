#include<bits/stdc++.h>
using namespace std;
pair<int,int> pyt[100010];
vector<int> s1[200010];
vector<int> s2[200010];
int wyn1[200010];
int wyn2[200010];
queue<int> kolejka;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,a,b,d,i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a>>b;
		pyt[i]={a,b};
		s1[a].push_back(b);
		s1[b].push_back(a);
		s2[a].push_back(b);
		s2[b].push_back(a);
	}
	for(i=2;i<2*n;i+=2)
	{
		s1[i].push_back(i-1);
		s1[i-1].push_back(i);
		s2[i].push_back(i+1);
		s2[i+1].push_back(i);
	}
	s1[2*n].push_back(2*n-1);
	s1[2*n-1].push_back(2*n);
	s2[2*n].push_back(1);
	s2[1].push_back(2*n);
	for(i=1;i<=2*n;i++)
	{
		if(wyn1[i]!=0)
			continue;
		wyn1[i]=1;
		kolejka.push(i);
		while(!kolejka.empty())
		{
			a=kolejka.front();
			kolejka.pop();
			d=s1[a].size();
			for(j=0;j<d;j++)
			{
				if(wyn1[s1[a][j]]==0)
				{
					wyn1[s1[a][j]]=(wyn1[a]%2)+1;
					kolejka.push(s1[a][j]);
				}
				else if(wyn1[s1[a][j]]==wyn1[a])
					goto next;
			}
		}
	}
	for(i=1;i<=n;i++)
		cout<<wyn1[pyt[i].first]<<" "<<wyn1[pyt[i].second]<<"\n";
	return 0;
	next:
	for(i=1;i<=2*n;i++)
	{
		if(wyn2[i]!=0)
			continue;
		wyn2[i]=1;
		kolejka.push(i);
		while(!kolejka.empty())
		{
			a=kolejka.front();
			kolejka.pop();
			d=s2[a].size();
			for(j=0;j<d;j++)
			{
				if(wyn2[s2[a][j]]==0)
				{
					wyn2[s2[a][j]]=(wyn2[a]%2)+1;
					kolejka.push(s2[a][j]);
				}
				else if(wyn2[s2[a][j]]==wyn2[a])
				{
					cout<<"-1";
					return 0;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
		cout<<wyn2[pyt[i].first]<<" "<<wyn2[pyt[i].second]<<"\n";
	return 0;
}