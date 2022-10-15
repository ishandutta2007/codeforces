#include<bits/stdc++.h>
using namespace std;
vector<int> G[100100];
long long Person[100100],TotalPerson[100100],H[100100];
bool OK;
void dfsCount(int x,int pa)
{
	for(int i=0;i<(G[x].size());i++)
		if(G[x][i]!=pa)
		{
			dfsCount(G[x][i],x);
			TotalPerson[x]+=TotalPerson[G[x][i]];
		}
	TotalPerson[x]+=Person[x];
}
void dfsSolve(int x,int pa)
{
	long long Total=0,Count=0;
	for(int i=0;i<(int)(G[x].size());i++)
		if(G[x][i]!=pa)
		{
			dfsSolve(G[x][i],x);
//			Total+=MustH[G[x][i]];
			Count+=H[G[x][i]];
		}
//	cout<<x<<" "<<TotalPerson[x]<<endl;
	long long Nega=TotalPerson[x]-H[x];
	if(Nega%2||Nega<0)
	{
		OK=false;
		return ;
	}
	Nega/=2;
	Total=H[x]+min(Nega,Person[x])-max(0ll,Person[x]-Nega);
//	cout<<Total<<" "<<Count<<"("<<x<<")\n";
	if(Total<Count)
	{
		OK=false;
//		cout<<"WRONG("<<x<<")\n";
		return ;
	}
	if((Total-Count)%2)
	{
		OK=false;
//		cout<<"WRONG("<<x<<")\n";
		return ;
	}
}
void Solve()
{
	int N;
	long long Ttl;
	cin>>N>>Ttl;
	OK=true;
	for(int i=0;i<N;i++)
	{
		TotalPerson[i]=0;
		cin>>Person[i];
		G[i].resize(0);
	}
	for(int i=0;i<N;i++)
		cin>>H[i];
	for(int i=1;i<N;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfsCount(0,-1);
	dfsSolve(0,-1);
	if(OK)
		puts("YES");
	else	puts("NO");
}
int main()
{
	int T;
	cin>>T;
	while(T--)
		Solve();
	return 0;
}