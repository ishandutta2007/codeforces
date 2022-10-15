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
ll x[200200];
ll psum[200200];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		ll s;
		scanf("%d%lld",&n,&s);
		for(int i=1;i<=n;i++)
			scanf("%lld",x+i);
		for(int i=1;i<=n;i++)
			psum[i]=psum[i-1]+x[i];
		int l=1,r=1;
		int ans=0;
		int xl=-1,xr=-1;
		while(l<=n)
		{
			while(r<=n&&psum[r]-psum[l-1]>=-s)
				r++;
			if(r-l>ans)
			{
				ans=r-l;
				xl=l;
				xr=r-1;
			}
			r--;
			int tmp=l;
			while(l<=n&&psum[l-1]>=psum[tmp-1])
				l++;
		}
		if(ans)
			printf("%d %d\n",xl,xr);
		else	puts("-1");
	}
	return 0;
}