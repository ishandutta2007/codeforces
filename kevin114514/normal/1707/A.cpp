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
int a[100100];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		int cnt=0;
		string ans;
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		for(int i=n;i>=1;i--)
			if(a[i]>cnt)
			{
				if(cnt+1<=q)
				{
					cnt++;
					ans+='1';
				}
				else	ans+='0';
			}
			else	ans+='1';
		rev(ans);
		cout<<ans<<endl;
	}
	return 0;
}