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
		vector<int> v;
		for(int i=0;i<n;i++)
			if(s[i]=='a')
				v.pb(i);
		int ans=55;
		for(int i=1;i<sz(v);i++)
			if(v[i]-v[i-1]==1)
			{
				ans=min(ans,2);
//				fl=1;
			}
			else if(v[i]-v[i-1]==2)
			{
				ans=min(ans,3);
//				fl=1;
			}
			else if(v[i]-v[i-1]==3&&s[v[i]-1]!=s[v[i]-2])
			{
				ans=min(ans,4);
//				fl=1;
			}
		for(int i=2;i<sz(v);i++)
			if(v[i]-v[i-1]==3&&v[i-1]-v[i-2]==3&&s[v[i]-1]!=s[v[i-1]-1])
				ans=min(ans,7);
		if(ans==55)
			puts("-1");
		else	cout<<ans<<endl;
	}
	return 0;
}