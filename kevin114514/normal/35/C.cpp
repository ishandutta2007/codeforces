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
int x[15],y[15];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
		cin>>x[i]>>y[i];
	int mxdist=-1;
	int ansx=1,ansy=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int mn=inf;
			for(int l=1;l<=k;l++)
				mn=min(mn,abs(i-x[l])+abs(j-y[l]));
			if(mn>mxdist)
			{
				ansx=i;
				ansy=j;
				mxdist=mn;
			}
		}
	cout<<ansx<<" "<<ansy<<endl;
	return 0;
}