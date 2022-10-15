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
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
vector<int> rk[(1<<18)];
char s[(1<<18)+10];
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	int len=(1<<n);
	for(int i=0;i<len;i++)
	{
		rk[i].resize(1);
		rk[i][0]=s[i]-'a'+1;
	}
	for(int i=1;i<=n;i++)
	{
		vector<pair<pii,pii>> vec;
		for(int j=0;j<len;j+=(1<<i))
		{
			for(int k=0;k<(1<<(i-1));k++)
				vec.pb(mp(mp(rk[j][k],rk[j+(1<<(i-1))][k]),mp(j,k))),
				vec.pb(mp(mp(rk[j+(1<<(i-1))][k],rk[j][k]),mp(j,k+(1<<(i-1)))));
			rk[j].resize((1<<i));
			rk[j+(1<<(i-1))].resize(0);
		}
		srt(vec);
		int cnt=0;
		for(int j=0;j<sz(vec);j++)
		{
			if(!j||vec[j].first!=vec[j-1].first)
				cnt++;
			rk[vec[j].second.first][vec[j].second.second]=cnt;
		}
	}
	int x=0;
	for(int i=0;i<len;i++)
		if(rk[0][i]==1)
			x=i;
	for(int i=0;i<len;i++)
		cout<<s[i^x];
	return 0;
}