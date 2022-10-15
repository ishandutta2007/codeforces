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
set<int> query(int l,int r)
{
	printf("? %d %d\n",l,r);
	fflush(stdout);
	set<int> ret;
	for(int i=l;i<=r;i++)
	{
		int x;
		scanf("%d",&x);
		ret.insert(x);
	}
	return ret;
}
void answer(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int l=1,r=n;
		while(l!=r)
		{
			int mid=(l+r)/2;
			set<int> st=query(l,mid);
			int cnt=0,sum=0;
			for(auto x:st)
			{
				if(x>mid&&x<=r)
					cnt++;
				if(x>=l&&x<=r)
					sum++;
			}
			if((sum-cnt)%2)
				r=mid;
			else	l=mid+1;
		}
		answer(l);
	}
	return 0;
}