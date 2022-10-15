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
int cnt[26];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		memset(cnt,0,sizeof(cnt));
		for(auto c:s)
			cnt[c-'a']++;
		for(int i=0;i<sz(s);i++)
			if(cnt[s[i]-'a']==1)
			{
				cout<<s.substr(i)<<endl;
				break;
			}
			else	cnt[s[i]-'a']--;
	}
	return 0;
}