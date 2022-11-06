#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(10);
typedef long long int ll;
typedef long double ld;
using namespace std;
// ll mod=67280421310721;
// ll mod=8589934592;
ll mod=1e9+7;
ll INF=1e18;
ll po(ll a,ll b){
	ll re=1;  
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
			re%=mod;
		}
		a=(a*a);
		a%=mod;
		b>>=1;
	}
	return re;
}
vector<int> pf[100005];
int pr[100005];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
    // ll gtest=0;
    // spre
	ll test=1;
	// cin>>test;
	while(test--)
	{
		FOR(i,2,100005)
		{
			if(pr[i]==0)
			{
				for(int j=2*i;j<100005;j+=i)
				{
					pr[j]=1;
					pf[j].pb(i);
				}
				pf[i].pb(i);
			}
			else
			{
				pr[i]=0;
			}
		}
		int n,q;
		cin>>n>>q;
		int next[n];
		int a[n];
		FOR(i,0,n)
		{
			cin>>a[i];
		}
		int r=0,cnt=0;
		FOR(i,0,n)
		{
			while(cnt==0 && r<n)
			{
				FOR(j,0,pf[a[r]].size())
				{
					pr[pf[a[r]][j]]++;
					// cout<<pf[a[r]][j]<<' ';
					if(pr[pf[a[r]][j]]==2)
					{
						cnt++;
					}
				}
				// cout<<'\n';
				r++;
			}
			if(cnt==0)
				next[i]=r-1;
			else
				next[i]=r-2;
			FOR(j,0,pf[a[i]].size())
			{
				pr[pf[a[i]][j]]--;
				if(pr[pf[a[i]][j]]==1)
				{
					cnt--;
				}
			}
		}
		int next300[n];
		int next3cn[n];
		FOR(i,0,n)
		{
			int u=0,v=i;
			while((v-i)<333 && v<n)
			{
				v=next[v]+1;
				u++;
			}
			next300[i]=v-1;
			next3cn[i]=u;
		}
		int l;
		FOR(z,0,q)
		{
			cin>>l>>r;
			r--;
			int v=l-1;
			int u=0;
			while(next300[v]<r)
			{
				u+=next3cn[v];
				v=next300[v]+1;
			}
			while(next[v]<r)
			{
				u++;
				v=next[v]+1;
			}
			cout<<u+1<<'\n';
		}
		// cout<<'\n';

	}
	return 0;
}