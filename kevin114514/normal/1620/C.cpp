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
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		ll x;
		cin>>n>>k>>x;
		x--;
		string S;
		cin>>S;
		vector<int> v;
		vector<int> u;
		int cnt=0;
		for(auto c:S)
		{
			if(c=='a')
			{
				v.pb(cnt);
				cnt=0;
			}
			else	cnt+=k;
		}
		v.pb(cnt);
		u.resize(sz(v));
		for(int i=sz(u)-1;i>=0;i--)
		{
			u[i]=x%(v[i]+1);
			x/=(v[i]+1);
		}
		for(int i=0;i<sz(u);i++)
		{
			if(i)
				cout<<"a";
			cout<<string(u[i],'b');
		}
		puts("");
	}
	return 0;
}