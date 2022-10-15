//Author: Kevin5307
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
#define longer __int128_t
void die(string S){puts(S.c_str());exit(0);}
int a[100100];
int ans[100100];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		set<int> st;
		for(int i=1;i<=n;i++)
		{
			st.insert(i);
			ans[i]=1;
		}
		for(int i=1;i<n;i++)
		{
			int x=max(0,a[i]-a[i+1]);
			if(x)
			{
				int y=*st.lower_bound(x);
				ans[y]=i+1;
				st.erase(y);
			}
		}
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}