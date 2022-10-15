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
void die(string S){puts(S.c_str());exit(0);}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		string s;
		cin>>n>>s;
		for(auto &c:s) c='9'+'0'-c;
		if(s[0]=='0')
		{
			for(auto &c:s) c++;
			s.back()++;
			for(int i=sz(s)-1;i;i--)
				if(s[i]>'9')
				{
					s[i]-=10;
					s[i-1]++;
				}
		}
		cout<<s<<endl;
	}
	return 0;
}