#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define int ll
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
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin>>t;
	while(t--)
	{
		multiset<int> st;
		int t;
		cin>>t;
		int sum=0;
		while(t--)
		{
			int c;
			cin>>c;
			st.insert(c);
			sum+=c;
		}
		vector<int> fib;
		int sf=1;
		fib.pb(1);
		int a=1,b=1;
		while(sf+b<=sum)
		{
			sf+=b;
			fib.pb(b);
			int c=a+b;
			a=b;
			b=c;
		}
		bool fl=1;
		rev(fib);
		for(auto x:fib)
		{
			auto it=st.end();
			it--;
			if(*it<x)
			{
				fl=0;
				break;
			}
			int y=*it-x;
			st.erase(it);
			auto it2=st.end();
			if(!sz(st)&&y)
			{
				fl=0;
				break;
			}
			if(!sz(st))
				break;
			it2--;
			if(y>*it2)
			{
				fl=0;
				break;
			}
			if(y)
				st.insert(y);
		}
		if(sf!=sum||!fl)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}