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
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		set<pii> ms;
		int mn=inf;
		for(int i=1;i<=n;i++)
			if(a[i]<mn)
			{
				mn=a[i];
				ms.insert(mp(i,a[i]));
			}
		while(m--)
		{
			int p,x;
			scanf("%d%d",&p,&x);
			if(ms.lower_bound(mp(p,0))->first==p)
				ms.erase(ms.lower_bound(mp(p,0)));
			a[p]-=x;
			ms.insert(mp(p,a[p]));
			auto it=ms.lower_bound(mp(p,a[p]));
			bool f=0;
			if(it!=ms.begin())
			{
				auto it2=it;
				it2--;
				if(it2->second<=it->second)
				{
					ms.erase(it);
					f=1;
				}
			}
			auto it3=it;
			it3++;
			if(!f)
				for(;it3!=ms.end();)
					if(it3->second>=it->second)
					{
						auto it4=it3;
						it4++;
						ms.erase(it3);
						it3=it4;
					}
					else break;
			printf("%d ",sz(ms));
		}
		puts("");
	}
	return 0;
}