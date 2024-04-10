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
int a[100100];
int f[100100];
map<int,int> Mp;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin>>t;
	while(t--)
	{
		Mp.clear();
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int pre=0;
		Mp[pre]=0;
		for(int i=1;i<=n;i++)
		{
			pre^=a[i];
			f[i]=f[i-1]+(a[i]>0);
			if(Mp.find(pre)!=Mp.end())
				f[i]=min(f[i],f[Mp[pre]]+(i-Mp[pre]-1));
			Mp[pre]=i;
		}
		cout<<f[n]<<'\n';
	}
	return 0;
}