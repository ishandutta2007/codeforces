#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
ll t[400004];
void build(ll a[], ll v, ll tl, ll tr) 
{
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = (t[v*2] | t[v*2+1]);
    }
}
ll sum(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return (sum(v*2, tl, tm, l, min(r, tm))
           | sum(v*2+1, tm+1, tr, max(l, tm+1), r));
}
void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
        t[v] = new_val;
//        cout<<tl<<' '<<new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = (t[v*2] | t[v*2+1]);
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		string s;
		cin>>s;
		ll n=s.size();
		ll a[n];
		FOR(i,0,s.size())
		a[i]=pow(2,s[i]-'a');
		build(a,1,0,n-1);
		ll q;
		cin>>q;
		FOR(i,0,q)
		{
			ll o;
			cin>>o;
			if(o==1)
			{
				ll p;
				char c;
				cin>>p>>c;
				ll g=c-'a';
				update(1,0,n-1,p-1 ,pow(2,g));
			}
			else
			{
				ll l,r;
				cin>>l>>r;
				ll f=sum(1,0,n-1,l-1,r-1);
				l=0;
//				cout<<f<<'\n';
				while(f>0)
				{
					if(f%2==1)
					l++;
					f>>=1;
				}
				cout<<l<<'\n';
			}
		}
		
	}
	return 0;
}