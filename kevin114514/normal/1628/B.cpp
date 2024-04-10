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
	cin.tie();
	cout.tie();
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		map<string,bool> Mp;
		int n;
		cin>>n;
		bool flag=0;
		while(n--)
		{
			string s;
			cin>>s;
			if(sz(s)==1)
				flag=1;
			string t=s;
			rev(t);
			if(Mp[t])
				flag=1;
			for(char c='a';c<='z'&&!flag;c++)
			{
				t=c+s;
				rev(t);
				if(Mp[t])
					flag=1;
			}
			t=s.substr(1);
			rev(t);
			if(Mp[t])
				flag=1;
			Mp[s]=1;
			t=s;
			rev(t);
			if(Mp[t])
				flag=1;
		}
		if(flag)
			puts("YES");
		else	puts("NO");
	}
	return 0;
}