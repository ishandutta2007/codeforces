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
char buff[200200];
int cnt[200200];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cin>>(buff+1);
		int res=inf;
		for(char c='a';c<='z'+1;c++)
		{
			vector<int> v;
			for(int i=1;i<=n;i++)
				if(buff[i]!=c)
					v.pb(i);
			bool f=1;
			for(int i=0;i<sz(v);i++)
				if(buff[v[i]]!=buff[v[sz(v)-i-1]])
					f=0;
			if(!f)
				continue;
			v.pb(0);
			v.pb(n+1);
			srt(v);
			for(int i=1;i<sz(v);i++)
				cnt[i]=0;
			for(int i=1;i<sz(v);i++)
			{
				for(int j=v[i-1]+1;j<v[i];j++)
					cnt[i]++;
			}
			int ans=0;
			for(int i=1;i<sz(v);i++)
				ans+=(cnt[i]-min(cnt[i],cnt[sz(v)-i]));
			res=min(res,ans);
		}
		if(res==inf)
			puts("-1");
		else	cout<<res<<endl;
	}
	return 0;
}