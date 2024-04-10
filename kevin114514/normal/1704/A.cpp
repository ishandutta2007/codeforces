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
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m;
		cin>>n>>m;
		string s,t;
		cin>>s>>t;
		string s1=s.substr(n-m+1);
		string t1=t.substr(1);
		bool f=0;
		for(int i=0;i<=n-m;i++)
			if(s[i]==t[0])
				f=1;
		if(f&&s1==t1)
			puts("YES");
		else	puts("NO");
	}
	return 0;
}