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
int k[110],h[110];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>k[i];
		for(int i=0;i<n;i++)
			cin>>h[i];
		vector<pii> v;
		for(int i=0;i<n;i++)
			v.pb(mp(k[i]-h[i]+1,k[i]));
		srt(v);
		int lst=0,lst2=-1;
		ll ans=0;
		for(auto p:v)
		{
			if(p.first>lst2)
			{
				ans+=1ll*(lst2-lst+1)*(lst2-lst+2)/2;
				lst=p.first;
				lst2=p.second;
			}
			else
			{
				lst2=max(lst2,p.second);
			}
		}
		cout<<ans+1ll*(lst2-lst+1)*(lst2-lst+2)/2<<endl;
	}
	return 0;
}