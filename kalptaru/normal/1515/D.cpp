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
struct nod
{
	int s,e;
	ll v;
};
bool che(nod a,nod b)
{
	if(a.s==b.s)
	{
		return a.e>b.e;
	}
	return a.s<b.s;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
    // freopen("java2016.in", "r", stdin);
    // freopen("java2016.out", "w", stdout);
    // ll gtest=0;
    // spre
	ll test=1;
	cin>>test;
	while(test--)
	{
		
		int n;
		cin>>n;
		int l,r;
		cin>>l>>r;
		int c[n];
		FOR(i,0,n)
		{
			cin>>c[i];
		}
		sort(c,c+l);
		sort(c+l,c+n);
		bool ch[n]={0};
		int o=l;
		int ans=min(l,r);
		// FOR(i,0,n)
		// {
		// 	cout<<c[i]<<' ';
		// }
		FOR(i,0,l)
		{
			while(o<n && c[o]<c[i])
			{
				o++;
			}
			if(o<n && c[i]==c[o])
			{
				ch[i]=1;
				ch[o]=1;
				o++;
				ans--;
			}
		}
		int p=-1;
		if(l>r)
		{
			int d=l-r;
			FOR(i,0,l)
			{
				if(ch[i])
					continue;
				if(c[i]==p)
				{
					p=-1;
					d-=2;
					ans++;
				}
				else
				{
					p=c[i];
				}
				if(d==0)
				{
					break;
				}
			}
			ans+=d;
		}
		else
		{
			int d=r-l;
			FOR(i,l,n)
			{
				if(ch[i])
					continue;
				if(c[i]==p)
				{
					p=-1;
					d-=2;
					ans++;
				}
				else
				{
					p=c[i];
				}
				if(d==0)
				{
					break;
				}
			}
			ans+=d;
		}
		cout<<ans<<'\n';
		
	}
	return 0;
}