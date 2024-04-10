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
int u[500500],v[500500];
bitset<4000> bs[2000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i];
		u[i]--;
		v[i]--;
	}
	for(int i=1;i<=m;i++)
		bs[u[i]][v[i]]=1;
	for(int i=0;i<n;i++)
		bs[i][i+n]=1;
	for(int i=0;i<n;i++)
	{
		if(!bs[i][i])
			for(int j=i+1;j<n;j++) if(bs[j][i])
			{
				swap(bs[i],bs[j]);
				break;
			}
		for(int j=0;j<n;j++) if(i!=j&&bs[j][i])
			bs[j]^=bs[i];
	}
	for(int i=1;i<=m;i++)
		if(bs[v[i]][u[i]+n])
			puts("NO");
		else	puts("YES");
	return 0;
}