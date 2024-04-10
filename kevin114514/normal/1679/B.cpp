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
int a[200200];
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	ll sum=0;
	set<int> st;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		sum+=a[i];
		st.insert(i);
	}
	int lst=0;
	while(q--)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(*st.lower_bound(x)==x)
			{
				sum+=y-a[x];
				a[x]=y;
			}
			else
			{
				sum+=y-lst;
				a[x]=y;
				st.insert(x);
			}
		}
		else
		{
			int y;
			scanf("%d",&y);
			sum=1ll*y*n;
			st.clear();
			lst=y;
		}
		printf("%lld\n",sum);
	}
	return 0;
}