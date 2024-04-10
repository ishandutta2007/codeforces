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
#define int ll
#define pii pair<int,int>
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
vector<int> large[200100],small[200100];
bool used[200100];
signed main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		for(int i=0;i<k;i++)
		{
			large[i].clear();
			small[i].clear();
		}
		int nl=n%m;
		int ns=m-nl;
		int tl=nl*((n+m-1)/m);
		int numl=(n+m-1)/m;
		int nums=n/m;
		int tot=k*tl;
//		cerr<<"# "<<tl<<endl;
		priority_queue<pii> pq;
		for(int i=0;i<tot%n;i++)
			pq.push(mp((tot+n-1)/n,i+1));
		for(int i=0;i<(n-tot%n);i++)
			pq.push(mp(tot/n,i+tot%n+1));
		for(int i=0;i<k;i++)
		{
			for(int j=1;j<=n;j++)
				used[j]=0;
			for(int j=0;j<tl;j++)
			{
				auto p=pq.top();
				pq.pop();
				large[i].pb(p.second);
				p.first--;
				pq.push(p);
				used[p.second]=1;
			}
			for(int j=1;j<=n;j++)
				if(!used[j])
					small[i].pb(j);
		}
		for(int i=0;i<k;i++)
		{
//			cerr<<"$ "<<sz(large[i])<<endl;
			for(int j=0;j<sz(large[i]);j++)
			{
				if(j%numl==0)
				{
					puts("");
					cout<<numl<<" ";
				}
				cout<<large[i][j]<<" ";
			}
			for(int j=0;j<sz(small[i]);j++)
			{
				if(j%nums==0)
				{
					puts("");
					cout<<nums<<" ";
				}
				cout<<small[i][j]<<" ";
			}
		}
		puts("");
	}
	return 0;
}