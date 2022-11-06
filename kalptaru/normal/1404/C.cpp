#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include<vector>
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
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
//			re%=mod;
		}
		a=(a*a);
//		a%=mod;
		b>>=1;
	}
	return re;
}
struct qu
{
	int x,y,i;
};
bool che(qu a,qu b)
{
	return a.y>b.y;
}
int t[2000000];
int find(int v, int tl, int tr, int x) 
{
    if (tl==tr) 
	{
        return t[v];
    }
    int tm = (tl + tr) / 2;
    if(x<=tm)
    return t[v]+find(v*2, tl, tm, x);
    return t[v]+find(v*2+1, tm+1, tr, x);
}
void update(int v,int tl,int tr,int l,int r)
{
	if (l > r) 
        return;
    if (l == tl && r == tr) {
        t[v]++;
        return;
    }
    int tm = (tl + tr) / 2;
    update(v*2, tl, tm, l, min(r, tm));
    update(v*2+1, tm+1, tr, max(l, tm+1), r);
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
		int n,q,o,l,r,mid,v;
		cin>>n>>q;
		int a[n];
		FOR(i,0,n)
		cin>>a[i];
		qu xy[q];
		FOR(i,0,q)
		{
			cin>>xy[i].x>>xy[i].y;
			xy[i].i=i;
		}
		sort(xy,xy+q,che);
		int ans[q];
		int j=0;
		FOR(i,0,n)
		{
			while(j<q && xy[j].y>=(n-i))
			{
//				cout<<xy[j].x<<' '<<xy[j].y<<"----\n";
				ans[xy[j].i]=find(1,0,n-1,xy[j].x);
				j++;
			}
			o=i+1-a[i];
//			cout<<"this is o"<<o<<' '<<i<<'\n';
			if(o<0)
			continue;
			if(o==0)
			{
				update(1,0,n-1,0,i);
				continue;
			}
			l=0,r=i;
			while(l<r)
			{
				mid=(l+r)/2;
				v=find(1,0,n-1,mid);
				if(v>=o)
				{
					l=mid+1;
				}
				else
				{
					r=mid;
				}
			}
			update(1,0,n-1,0,l-1);
		}
		while(j<q)
		{
			ans[xy[j].i]=find(1,0,n-1,xy[j].x);
			j++;
		}
		FOR(i,0,q)
		cout<<ans[i]<<'\n';
	}
	return 0;
}