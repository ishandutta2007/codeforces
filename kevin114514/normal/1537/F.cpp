#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
void die(string S){puts(S.c_str());exit(0);}
int p[200200],t[200200];
int color[200200];
vector<int> G[200200];
bool canbp(int x,int C)
{
	if(color[x]&&color[x]!=C)
		return false;
	if(color[x])
		return true;
	color[x]=C;
	bool f=true;
	for(int i=0;i<sz(G[x]);i++)
		f&=canbp(G[x][i],3-C);
	return f;
}
void Main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		cin>>t[i];
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].pb(y);
		G[y].pb(x);
	}
	if(!canbp(1,1))
	{
		ll cnt=0;
		for(int i=1;i<=n;i++)
			cnt+=(t[i]-p[i]);
		if(cnt%2==0)
			puts("YES");
		else	puts("NO");
		for(int i=1;i<=n;i++)
		{
			p[i]=t[i]=color[i]=0;
			G[i].clear();
		}
		return ;
	}
	ll cnt=0;
	for(int i=1;i<=n;i++)
		if(color[i]==1)
		{
			cnt+=p[i];
			cnt-=t[i];
		}
		else
		{
			cnt-=p[i];
			cnt+=t[i];
		}
	if(cnt)
		puts("NO");
	else	puts("YES");
	for(int i=1;i<=n;i++)
	{
		p[i]=t[i]=color[i]=0;
		G[i].clear();
	}
	return ;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
		Main();
}