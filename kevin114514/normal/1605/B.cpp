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
void die(string S){puts(S.c_str());exit(0);}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int cnt1=0;
		for(int i=0;i<s.length();i++)
			if(s[i]=='1')
				cnt1++;
		int cnt0=0;
		bool fl=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='0')
				cnt0++;
			if((i+1-cnt0)==(s.length()-cnt1-cnt0))
			{
				vector<int> v;
				for(int j=0;j<=i;j++)
					if(s[j]=='1')
						v.pb(j);
				for(int j=i+1;j<n;j++)
					if(s[j]=='0')
						v.pb(j);
				if(sz(v))
				cout<<1<<endl;
				cout<<sz(v)<<" ";
				for(int i=0;i<sz(v);i++)
					cout<<v[i]+1<<" ";
				puts("");
				fl=1;
				break;
			}
		}
		if(!fl)
			puts("0");
	}
	return 0;
}