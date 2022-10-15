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
#define int ll
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll h1,d1,h2,d2;
		cin>>h1>>d1>>h2>>d2;
		int k;
		ll w,a;
		cin>>k>>w>>a;
		for(int i=0;i<=k;i++)
		{
			int h3=a*i+h1;
			int d3=w*(k-i)+d1;
			int cntp=(h2+d3-1)/d3;
			int cntm=(h3+d2-1)/d2;
			if(cntp<=cntm)
			{
				puts("YES");
				goto next;
			}
		}
		puts("NO");
		next:;
	}
	return 0;
}