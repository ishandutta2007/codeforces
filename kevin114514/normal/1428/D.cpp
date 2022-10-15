#include<bits/stdc++.h>
using namespace std;
int turns[100100];
int nxt[100100][5];
vector<pair<int,int> > points;
int done[100100];
int row;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>turns[i];
	for(int i=1;i<=n;i++)
		for(int j=0;j<4;j++)
		{
			nxt[i][j]=max(nxt[i-1][j],i+1);
			while(nxt[i][j]<=n&&turns[nxt[i][j]]!=j)
				nxt[i][j]++;
		}
	for(int i=1;i<=n;i++)
		nxt[i][4]=min(min(nxt[i][1],nxt[i][2]),nxt[i][3]);
	bool OK=true;
	for(int i=1;i<=n;i++)
	{
		if(turns[i]==0||done[i]==2)
			continue;
		if(turns[i]==1)
		{
			row++;
			points.push_back(make_pair(row,i));
			done[i]=1;
			continue;
		}
		if(turns[i]==2)
		{
			int nxt1=nxt[i][1];
			while(done[nxt1])
				nxt1=nxt[nxt1][1];
			int tmp=nxt[i][1];
			while(tmp!=nxt1)
			{
				int ttmp=nxt[tmp][1];
				nxt[tmp][1]=nxt1;
				tmp=ttmp;
			}
			if(nxt1>n)
			{
				OK=false;
				break;
			}
			row++;
			points.push_back(make_pair(row,i));
			points.push_back(make_pair(row,nxt1));
			done[i]=done[nxt1]=2;
			continue;
		}
		if(turns[i]==3)
		{
			int nnxt=nxt[i][4];
			while(done[nnxt])
			{
				nnxt=nxt[nnxt][4];
			}
			int tmp=nxt[i][4];
			while(tmp!=nnxt)
			{
				int ttmp=nxt[tmp][4];
				nxt[tmp][4]=nnxt;
				tmp=ttmp;
			}
			if(nnxt>n)
			{
				OK=false;
				break;
			}
			row++;
			points.push_back(make_pair(row,i));
			points.push_back(make_pair(row,nnxt));
			done[i]=1;
			done[nnxt]=1;
			continue;
		}
	}
	if(!OK)
		puts("-1");
	else
	{
		cout<<(int)(points.size())<<endl;
		for(int i=0;i<(int)(points.size());i++)
			cout<<points[i].first<<" "<<points[i].second<<endl;
	}
	return 0;
}