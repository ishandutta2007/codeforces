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
int cnt[200200];
bool vis[200200];
int req[200200];
int mnreq[200200];
int main()
{
	req[0]=1;
	for(int i=1;i<200200;i++)
	{
		for(int j=0;j<20;j++)
			if((1<<j)>=i)
			{
				req[i]=(1<<j)-i;
				break;
			}
	}
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cnt[i]=vis[i]=0;
		vector<int> v;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			cnt[x]++;
		}
		int sum=0;
		vis[0]=1;
//		vector<int> vec;
		v.pb(0);
		for(int i=1;i<=n;i++)
		{
			sum+=cnt[i];
			vis[sum]=1;
			v.pb(sum);
			mnreq[i]=req[sum]+req[0];
			for(int j=0;(1<<j)<=sum;j++)
			{
				int x=v[ub(v,1<<j)-1];
				mnreq[i]=min(req[x]+req[sum-x],mnreq[i]);
			}
//			if(!sum)	mnreq[i]=2;
//			else if(sum=1) mnreq[i]=1;
//			else if(__builtin_popcount(sum)==1)
//				mnreq[i]=1-vis[sum/2];
//			else if(__builtin_popcount(sum)==2)
//			{
//				int a=(-sum)&sum;
//				if(vis[a]||vis[sum-a])
//					mnreq[i]=0;
//				else if(a==(sum-a)/2)
//				{
//					
//				}
//				else
//				{
//					
//				}
//			}
		}
		int ans=req[n]+req[0]+req[0];
		for(int i=1;i<=n;i++)
		{
			ans=min(ans,mnreq[i]+req[sum-v[i]]);
		}
		cout<<ans<<endl;
	}
	return 0;
}