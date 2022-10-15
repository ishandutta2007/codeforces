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
#define int ll
void die(string S){puts(S.c_str());exit(0);}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int x;
		cin>>x;
		bool od=0;
		int cnt=0;
		int co2=0;
		int ans=0;
		int cc=0;
		int g5=0;
		for(int i=2;i<n;i++)
		{
			cin>>x;
			if(x)
				cc++;
			if(x>=2)
				cnt++;
			if(x>=2&&x%2)
				co2++;
			ans+=(x+1)/2;
			if(x%2)
				od=1;
			if(x>=4)
				g5++;
		}
		cin>>x;
		if(cc==1)
		{
			if(od&&n>3&&g5)
				cout<<ans+1<<endl;
			else if(od)
				puts("-1");
			else	cout<<ans<<endl;
		}
		else
		{
			if((od&&!cnt))
				puts("-1");
			else	cout<<ans<<endl;
		}
	}
	return 0;
}