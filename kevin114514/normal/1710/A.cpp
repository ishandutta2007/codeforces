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
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		ll cn=0,cm=0;
		ll cn2=0,cm2=0;
		while(k--)
		{
			int x;
			scanf("%d",&x);
			int xn=x/n;
			int xm=x/m;
			if(xn>=2)
				cn+=xn-2,cn2+=2;
			if(xm>=2)
				cm+=xm-2,cm2+=2;
		}
		cm2=min(cm2,n/2ll*2ll);
		cn2=min(cn2,m/2ll*2ll);
		m-=cn2;
		n-=cm2;
		if(cn>=m||cm>=n)
			puts("Yes");
		else	puts("No");
	}
	return 0;
}