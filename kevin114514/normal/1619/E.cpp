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
#define int ll
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int cnt[200200];
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<=n;i++)
			cnt[i]=0;
		multiset<int> ms;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			cnt[x]++;
			ms.insert(x);
		}
		int tot=0;
		bool flg=0;
		for(int i=0;i<=n;i++)
		{
			if(flg)
			{
				cout<<-1<<" ";
				continue;
			}
			else	cout<<tot+cnt[i]<<" ";
			if(!sz(ms))
			{
				flg=1;
				continue;
			}
			auto it=ms.upper_bound(i);
			if(it==ms.begin())
			{
				flg=1;
				continue;
			}
			it--;
			tot+=i-*it;
			ms.erase(it);
		}
		puts("");
	}
	return 0;
}