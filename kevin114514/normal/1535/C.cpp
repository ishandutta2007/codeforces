#include<bits/stdc++.h>
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
void die(string S){puts(S.c_str());exit(0);}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int n=s.length();
		int pos=0,col=-1;
		int st=0;
		ll ans=0;
		for(int i=0;i<n;i++)
			if(s[i]=='?')
				ans+=(i-st+1);
			else
			{
				if(col>=0&&((i-pos)-(col-(s[i]-'0')))%2!=0)
					st=pos+1;
				ans+=(i-st+1);
				pos=i;
				col=s[i]-'0';
			}
		cout<<ans<<endl;
	}
	return 0;
}