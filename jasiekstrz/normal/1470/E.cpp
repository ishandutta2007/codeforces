#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int L=15;
int n;
const long long INF=(long long)1e18+7;
int t[30010];
vector<pair<int,long long>> e[30010][5];
pair<long long,long long> jmp[60010][5][16];
long long choose[30010][5];
inline long long cnt(int d,int c)
{
	if(d==0)
		return 1;
	long long ans=1;
	while(c--)
		ans+=choose[d-1][c+1];
	return min(ans,INF);
}
inline int f(int i,int j,int x,long long y)
{
	//cerr<<i<<" "<<j<<" "<<x<<" "<<y<<" | ";
	for(int it=L;it>=0;it--)
	{
		if(i+(1<<it)<=n && y>jmp[i][j][it].fi && y<=jmp[i][j][it].se)
		{
			y-=jmp[i][j][it].fi;
			i+=(1<<it);
		}
	}
	//cerr<<i<<" "<<j<<" "<<x<<" "<<y<<"\n";
	if(i>x)
		return t[x];
	unsigned it;
	for(it=0;it<e[i][j].size() && e[i][j][it].se<y;it++);
	it--;
	//cerr<<e[i][j][it].fi<<" "<<e[i][j][it].se<<"\n";
	if(i+e[i][j][it].fi>=x)
		return t[2*i+e[i][j][it].fi-x];
	return f(i+e[i][j][it].fi+1,j-e[i][j][it].fi,x,y-e[i][j][it].se);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tt,c,q,i,j,k;
	cin>>tt;
	while(tt--)
	{
		cin>>n>>c>>q;
		for(i=1;i<=n;i++)
			cin>>t[i];
		choose[0][0]=1;
		for(i=1;i<=n;i++)
		{
			choose[i][0]=1;
			for(j=1;j<=c;j++)
				choose[i][j]=min(INF,choose[i-1][j-1]+choose[i-1][j]);
		}
		//cerr<<cnt(2,1)<<"\n";
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=c;j++)
			{
				e[i][j].clear();
				vector<pair<int,int>> tmp;
				for(k=0;k<=j && i+k<=n;k++)
					tmp.push_back({t[i+k],k});
				sort(tmp.begin(),tmp.end());
				long long xd=0;
				for(auto v:tmp)
				{
					e[i][j].push_back({v.se,xd});
					//cerr<<"e["<<i<<"]["<<j<<"]: "<<v.se<<" "<<xd<<"\n";
					if(v.se==0)
						jmp[i][j][0].fi=xd;
					xd=min(INF,xd+cnt(n-i-v.se,j-v.se));
					if(v.se==0)
						jmp[i][j][0].se=xd;
				}
			}
		}
		for(i=n;i>=1;i--)
		{
			for(j=0;j<=c;j++)
			{
				for(k=1;k<=L;k++)
				{
					jmp[i][j][k].fi=min(INF,jmp[i][j][k-1].fi+jmp[i+(1<<(k-1))][j][k-1].fi);
					jmp[i][j][k].se=min(jmp[i][j][k-1].se,
							jmp[i][j][k-1].fi+jmp[i+(1<<(k-1))][j][k-1].se);
				}
			}
		}
		while(q--)
		{
			long long a,b;
			cin>>a>>b;
			if(cnt(n,c)<b)
				cout<<"-1\n";
			else
				cout<<f(1,c,a,b)<<"\n";
		}
	}
	return 0;
}