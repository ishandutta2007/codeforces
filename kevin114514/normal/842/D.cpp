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
int cnt[(1<<21)];
map<int,bool> Mp;
int main()
{
	int n,m;
	cin>>n>>m;
	while(n--)
	{
		int x;
		cin>>x;
		if(Mp[x])
			continue;
		Mp[x]=1;
		int u=1;
		cnt[u]++;
		for(int i=19;i>=0;i--)
		{
			u<<=1;
			u|=(x>>i&1);
			cnt[u]++;
//			cout<<u<<endl;
		}
	}
	int x=0;
	while(m--)
	{
		int xx=0;
		cin>>xx;
		x^=xx;
		int u=1;
		int uu=0;
		int havenum=(1<<20);
		for(int i=19;i>=0;i--)
		{
//			cout<<u<<" "<<cnt[u]<<endl;
			havenum/=2;
			if(x>>i&1)
			{
				if(cnt[u<<1|1]==havenum)
				{
					u<<=1;
					uu=uu<<1|1;
				}
				else
				{
					u=u<<1|1;
					uu<<=1;
				}
			}
			else
			{
				if(cnt[u<<1]!=havenum)
				{
					u<<=1;
					uu<<=1;
				}
				else
				{
					u=u<<1|1;
					uu=uu<<1|1;
				}
			}
		}
		cout<<uu<<endl;
	}
	return 0;
}