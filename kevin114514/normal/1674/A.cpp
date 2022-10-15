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
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		if(x==y)
			puts("1 1");
		else
		{
			for(int i=2;i<=y/x;i++)
			{
				int z=x;
				int cnt=0;
				while(x<y)
				{
					cnt++;
					x*=i;
				}
				if(x==y)
				{
					cout<<cnt<<" "<<i<<endl;
					goto fail;
				}
				x=z;
			}
			puts("0 0");
			fail:;
		}
	}
	return 0;
}