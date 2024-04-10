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
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<pii> v;
		for(int i=0;i<n;i++)
		{
			int k;
			cin>>k;
			int mx=0;
			for(int j=0;j<k;j++)
			{
				int x;
				cin>>x;
				mx=max(mx,x-j);
			}
			v.pb(mp(mx,k));
		}
		srt(v);
		int l=0,r=1e9+1;
		while(l<r)
		{
			int mid=(l+r)/2;
			bool flag=true;
			int tmp=mid;
			for(int i=0;i<n;i++)
				if(tmp<=v[i].first)
				{
					flag=false;
					break;
				}
				else	tmp+=v[i].second;
			if(flag)
				r=mid;
			else	l=mid+1;
		}
		cout<<l<<endl;
	}
	return 0;
}