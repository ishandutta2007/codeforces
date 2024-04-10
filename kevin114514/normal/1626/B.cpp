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
		string s;
		cin>>s;
		for(int i=sz(s)-1;i>=0;i--)
			if(s[i]+s[i+1]-'0'-'0'>=10)
			{
				s[i+1]=s[i]+s[i+1]-'0'-10;
				s[i]='1';
				cout<<s<<endl;
				goto yes;
			}
		s[1]=s[0]+s[1]-'0';
		s=s.substr(1);
		cout<<s<<endl;
		yes:;
	}
	return 0;
}