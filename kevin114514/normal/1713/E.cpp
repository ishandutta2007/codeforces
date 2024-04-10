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
int fa[1010],len[1010];
int anc(int x)
{
	if(fa[x]==x)
		return x;
	int f=fa[x];
	fa[x]=anc(fa[x]);
	len[x]+=len[f];
	return fa[x];
}
int a[1010][1010];
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
			for(int j=1;j<=n;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++)
			fa[i]=i,len[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++) if(a[i][j]!=a[j][i])
			{
				bool need=(a[i][j]>a[j][i]);
				int xx=anc(i),yy=anc(j);
//				cout<<i<<" "<<j<<" "<<anc(i)<<" "<<anc(j)<<endl;
//				cout<<len[i]<<" "<<len[j]<<endl;
				if(xx==yy)
				{
					if((len[i]+len[j])%2)
					{
						swap(a[i][j],a[j][i]);
					}
				}
				else
				{
					fa[xx]=yy;
					len[xx]=(len[i]+len[j]+need)%2;
					if(need)
						swap(a[i][j],a[j][i]);
				}
			}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cout<<a[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}