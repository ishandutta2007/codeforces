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
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<int> v;
		bool have02=0,have1=0;
		while(n--)
		{
			int x;
			scanf("%d",&x);
			v.pb(x);
			if(x==1)
				have1=1;
			if(x==0||x==2)
				have02=1;
		}
		if(have02&&have1)
			puts("NO");
		else
		{
			if(have1)
			{
				srt(v);
				for(int i=0;i<sz(v)-1;i++)
					if(v[i]+1==v[i+1])
					{
						puts("NO");
						goto fail;
					}
			}
			puts("YES");
			fail:;
		}
	}
	return 0;
}