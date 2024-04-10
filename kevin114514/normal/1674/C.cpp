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
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		string a,b;
		cin>>a>>b;
		if(b=="a")
			puts("1");
		else
		{
			bool fl=1;
			for(auto c:b) if(c=='a')
				fl=0;
			if(!fl)
				puts("-1");
			else
			{
				ll ans=1;
				int n=sz(a);
				while(n--)
					ans*=2;
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}