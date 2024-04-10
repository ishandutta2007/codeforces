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
int x[100100];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x[i]);
			if(!x[i])
				cnt++;
		}
		if(!cnt)
			puts("1");
		else if(cnt==n)
			puts("0");
		else
		{
			int l=1,r=n;
			while(l<=n&&!x[l]) l++;
			while(r>=1&&!x[r]) r--;
			if(l+n-r-1==cnt)
				puts("1");
			else	puts("2");
		}
	}
	return 0;
}