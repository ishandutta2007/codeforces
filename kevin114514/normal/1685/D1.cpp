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
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
#define longer __int128_t
void die(string S){puts(S.c_str());exit(0);}
int fa[220];
int p[220];
int anc(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=anc(fa[x]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			fa[i]=i;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			p[x]=i;
			fa[anc(x)]=anc(p[x]);
		}
		for(int i=1;i<n;i++) if(anc(i)!=anc(i+1))
		{
			swap(p[i],p[i+1]);
			fa[anc(i)]=anc(i+1);
		}
		int x=1;
		for(int i=1;i<=n;i++)
		{
			cout<<x<<" ";
			x=p[x];
		}
		cout<<'\n';
	}
	return 0;
}