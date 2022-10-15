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
ll h[200100];
ll h2[200100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>h[i];
		ll l=0,r=1e9;
		while(l<r)
		{
			ll mid=(l+r+1)/2;
			for(int i=1;i<=n;i++)
				h2[i]=h[i];
			bool flag=1;
			for(int i=n;i>=3;i--)
				if(h2[i]<mid)
					flag=0;
				else
				{
					h2[i-1]+=min(h2[i]-mid,h[i])/3;
					h2[i-2]+=2*(min(h2[i]-mid,h[i])/3);
				}
			if(flag&&min(h2[1],h2[2])>=mid)
				l=mid;
			else	r=mid-1;
		}
		cout<<l<<endl;
	}
	return 0;
}