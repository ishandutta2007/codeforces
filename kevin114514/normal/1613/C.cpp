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
#define int ll
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,h;
		cin>>n>>h;
		vector<int> v;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			v.pb(x);
		}
		srt(v);
		v.pb(2e18);
		int l=0,r=1e18;
		while(l<r)
		{
			int mid=(l+r)/2;
			int cnt=0;
			for(int i=0;i<n;i++)
				cnt+=min(mid,v[i+1]-v[i]);
			if(cnt>=h)
				r=mid;
			else	l=mid+1;
		}
		cout<<l<<endl;
	}
	return 0;
}