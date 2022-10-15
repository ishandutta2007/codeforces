#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
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
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
int fa[1010];
int siz[1010];
int anc(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=anc(fa[x]);
}
int main()
{
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		fa[i]=i,
		siz[i]=1;
	int cnt=0;
	while(d--)
	{
		int u,v;
		cin>>u>>v;
		u=anc(u);
		v=anc(v);
		if(u==v)
			cnt++;
		else
		{
			fa[u]=v;
			siz[v]+=siz[u];
			siz[u]=0;
		}
		vector<int> vv;
		for(int i=1;i<=n;i++)
			vv.pb(siz[i]);
		rsrt(vv);
		int ans=0;
		for(int i=0;i<min(n,cnt+1);i++)
			ans+=vv[i];
		cout<<ans-1<<endl;
//		cout<<min(n-1,*max_element(siz+1,siz+n+1)+cnt-1)<<endl;
	}
	return 0;
}