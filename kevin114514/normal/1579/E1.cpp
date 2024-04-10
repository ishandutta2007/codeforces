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
bool have[200200];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			have[i]=0;
		vector<int> v,res,mn;
		int m=1e9;
		int pos=0;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			if(m>x)
			{
				m=x;
				pos=i;
			}
			mn.pb(pos);
			v.pb(x);
		}
		int x=mn[n-1];
		while(x>=0)
		{
			res.pb(v[x]);
			have[v[x]]=1;
			if(x)
				x=mn[x-1];
			else	x=-1;
		}
		for(int i=0;i<n;i++)
			if(!have[v[i]])
				res.pb(v[i]);
		for(int i=0;i<n;i++)
			cout<<res[i]<<" ";
		puts("");
	}
	return 0;
}