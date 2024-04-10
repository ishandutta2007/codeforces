#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;
struct tri
{
	int i,j,k;
};
ll po(ll a,ll b)
{
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
ll t[1000001][2];
map<ll,int> com;
void update(int v, int tl, int tr, int pos, ll new_val,int o) {
    if (tl == tr) {
        t[v][o] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val,o);
        else
            update(v*2+1, tm+1, tr, pos, new_val,o);
        t[v][o] = t[v*2][o] + t[v*2+1][o];
    }
}
ll sum(int v, int tl, int tr, int l, int r,int o) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v][o];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm),o)
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r,o);
}
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		pair<int,ll> c[n];
		vector<ll> oc;
		FOR(i,0,n)
		{
			cin>>c[i].first>>c[i].second;
			if(c[i].second>0)
			oc.pb(c[i].second);
		}
		sort(oc.begin(),oc.end());
		oc.pb(1000000007);
		int j=0;
		FOR(i,1,oc.size())
		{
			if(oc[i]!=oc[i-1])
			{
				com[oc[i-1]]=j;
				j++;
			}
		}
		set<ll> lig,fir;
		ll to=0,t,d,lc=0,fc=0,ans;
		FOR(i,0,n)
		{
//			cout<<'k';
			t=c[i].first;
			d=c[i].second;
			to+=d;
			if(t==0)
			{
				if(d<0)
				{
					d*=-1;
					fir.erase(d);
					fc--;
					update(1,0,j-1,com[d],0,0);
					update(1,0,j-1,com[d],0,1);
				}
				else
				{
					fir.insert(d);
					fc++;
					update(1,0,j-1,com[d],1,0);
					update(1,0,j-1,com[d],d,1);
				}
			}
			else
			{
				if(d<0)
				{
					d*=-1;
					lig.erase(d);
					lc--;
					update(1,0,j-1,com[d],0,0);
					update(1,0,j-1,com[d],0,1);
				}
				else
				{
					lig.insert(d);
					lc++;
					update(1,0,j-1,com[d],1,0);
					update(1,0,j-1,com[d],d,1);
				}
			}
//			cout<<'l';
			int l=0,r=j-1,mid;
			ll cn,z=0;
			while(l<r)
			{
				mid=(l+r)/2;
				cn=sum(1,0,j-1,mid,j-1,0);
				if(cn<=lc)
				{
					r=mid;
				}
				else
				{
					l=mid+1;
				}
			}
			ans=sum(1,0,j-1,l,j-1,1);
//			cout<<j-1<<' '<<mid<<' '<<lc<<'\n';
			if(fc==0)
			{
				if(lc==0)
				{
					cout<<0<<'\n';
					continue;
				}
				else
				{	
					ans-=(*(lig.begin()));
				}
			}
			else
			{
				if(lc==0)
				{
					cout<<to<<'\n';
					continue;
				}
				else
				{
					ans-=(max(z,*(lig.begin())-*(--fir.end())));
				}
			}
			cout<<to+ans<<'\n';
		}
		
	}
	return 0;
}