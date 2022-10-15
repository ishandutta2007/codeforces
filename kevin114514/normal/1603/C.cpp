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
const int maxn=100000;
//int BIT[maxn];
//void upd(int x,int p)
//{
//	
//}
int x[maxn];
const ll mod=998244353;
pii solve(int a,int b)
{
	return mp(a/((a+b-1)/b),(a-1)/b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",x+i);
		stack<pii> v;
		ll sum=0;
		for(int i=n-1;i>=0;i--)
		{
			stack<pii> u;
			u.push(mp(x[i],1));
			while(!v.empty())
			{
				pii p=v.top();
				v.pop();
				pii ans=solve(x[i],p.first);
				sum=(sum+1ll*ans.second*p.second%mod*(i+1)%mod)%mod;
				if(!u.empty()&&u.top().first==ans.first)
				{
					int x=p.second+u.top().second;
					u.pop();
					u.push(mp(ans.first,x));
				}
				else	u.push(mp(ans.first,p.second));
			}
			v=u;
		}
		printf("%lld\n",sum);
	}
	return 0;
}