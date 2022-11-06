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
#define spre cout<<fixed<<setprecision(15);
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
// ll mod=8589934592;
const ll mod=1000000007;
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
ll t[2000005],y[2000005];
bool marked[2000005];
int maxl=300005;
void push(int v,int l,int r) {
    if (marked[v]) 
    {
    	int mid=(l+r)/2;
        y[v*2] += y[v];
        y[v*2+1] += y[v];
        t[v*2] += (mid-l+1)*y[v];
        t[2*v+1] += (r-mid)*y[v];
        y[v]=0;
        marked[v*2] = marked[v*2+1] = true;
        marked[v] = false;
    }
}
void update(int v, int tl, int tr, int l, int r, ll val) {
    if (l > r) 
        return;
    // cout<<tl<<' '<<tr<<' '<<v<<'\n';
    if (l == tl && tr == r) 
    {
    	// cout<<v<<'\n';
        y[v]+=val;
        t[v]+=((tr-tl+1)*val);
        marked[v] = true;
    } 
    else 
    {
        push(v,tl,tr);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, val);
        t[v]=t[2*v]+t[2*v+1];
    }
}
ll get(int v, int tl, int tr, int k) 
{

    
    // cout<<tl<<' '<<tr<<' '<<v<<'\n';
    if (tl == tr) 
    {
    	// cout<<v<<'\n';
    	if(k<=t[v])
        	return tl;
        else
        	return -1;
    }
    push(v,tl,tr);
    int tm = (tl + tr) / 2;
    if (k<=t[2*v]) 
        return get(v*2, tl, tm, k);
    else
        return get(v*2+1, tm+1, tr, k-t[2*v]);
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
	ll test=1;
	// cin>>test;
	FOR(gtest,0,test)
	{
		int n;
		ll k;
		cin>>n>>k;
		ll l[n];
		FOR(i,0,n)
		{
			cin>>l[i];
		}
		sort(l,l+n,greater<ll>());
		update(1,0,maxl,0,0,1);
		ll ans=INF;
		ll o;
		FOR(i,0,n)
		{
			o=get(1,0,maxl,1);
			// cout<<o<<'\n';
			update(1,0,maxl,o,o,-1);
			if((l[i]%2)==0)
			{
				update(1,0,maxl,o+2,o+1+(l[i]/2),1);
				update(1,0,maxl,o+2,o+(l[i]/2),1);
			}
			else
			{
				// cout<<l[i]<<"[[[[\n";
				update(1,0,maxl,o+2,o+1+(l[i]/2),2);
				// FOR(j,0,25)
				// {
				// 	cout<<j<<' '<<t[j]<<' '<<y[j]<<'\n';
				// }
			}
			o=get(1,0,maxl,k);
			if(o>0)
			{
				ans=min(ans,o);
			}
		}
		if(ans==INF)
			cout<<-1;
		else
			cout<<ans;
	}
	return 0;
}