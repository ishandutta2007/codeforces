#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
vector<long long> s[300010];
long long c[300010];
long long pot[300010];
long long wlk;
long long DFS(long long x,long long col)
{
	long long d,a,w,i;
	c[x]=col;
	wlk++;
	w=0;
	if(col==1)
	{
		col=2;
		w=1;
	}
	else
		col=1;
	d=s[x].size();
	for(i=0;i<d;i++)
	{
		if(c[s[x][i]]==0)
		{
			a=DFS(s[x][i],col);
			if(a==-1)
				return -1;
			w+=a;
		}
		else if(c[s[x][i]]!=col)
			return -1;
	}
	return w;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long q,n,m,mn,a,b,w,qi,i;
	cin>>q;
	mn=0;
	pot[0]=1;
	for(qi=1;qi<=q;qi++)
	{
		cin>>n>>m;
		while(mn<n)
		{
			mn++;
			pot[mn]=(pot[mn-1]*2)%mod;
		}
		for(i=1;i<=m;i++)
		{
			cin>>a>>b;
			s[a].push_back(b);
			s[b].push_back(a);
		}
		w=1;
		for(i=1;i<=n;i++)
		{
			if(c[i]!=0)
				continue;
			wlk=0;
			a=DFS(i,1);
			if(a==-1)
			{
				cout<<"0\n";
				goto end;
			}
			w=(((w*pot[a])%mod)+((w*pot[wlk-a])%mod))%mod;
		}
		cout<<w<<"\n";
		end:
		for(i=1;i<=n;i++)
		{
			s[i].clear();
			c[i]=0;
		}
	}
	return 0;
}