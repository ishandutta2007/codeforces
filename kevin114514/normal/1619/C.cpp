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
		string a,b;
		cin>>a>>b;
		a="00000000000000000000"+a;
		rev(a);
		int p=sz(b)-1;
		string ans;
		bool flg=0;
		int p1=0;
		for(auto c:a)
		{
			if(p<0)
			{
				for(int i=p1;i<sz(a);i++)
					if(a[i]!='0')
						flg=1;
				break;
			}
			if(b[p]>=c)
				ans+=b[p]-c+'0';
			else if(p>0&&b[p-1]=='1')
			{
				ans+=b[p]-c+'0'+10;
				p--;
			}
			else
			{
				flg=1;
				break;
			}
			p--;
			p1++;
		}
		if(!flg)
		{
			rev(ans);
			int p=0;
			while(p<sz(ans)-1&&ans[p]=='0')
				p++;
			cout<<ans.substr(p)<<endl;
		}
		else	puts("-1");
	}
	return 0;
}