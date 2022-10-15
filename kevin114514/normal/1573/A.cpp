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
		string s;
		cin>>n>>s;
		int ans=0;
		while(true)
		{
			int ind=-1;
			for(int i=0;i<n;i++)
				if(s[i]!='0')
					ind=i;
			if(ind==-1)
				break;
			if(ind==n-1)
			{
				ans+=s[ind]-'0';
				s[ind]='0';
			}
			else
			{
				ans++;
				ans+=s[ind]-'0';
				s[ind]='0';
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}