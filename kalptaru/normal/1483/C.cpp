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
#define spre cout<<fixed<<setprecision(1);
typedef long long int ll;
using namespace std;
// ll mod=67280421310721;
// ll mod=8589934592;
const ll mod=998244353;
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
bool marked[2000000];
ll t[2000000];
void push(int v) {
    if (marked[v]) {
        t[v*2] = t[v*2+1] = t[v];
        marked[v*2] = marked[v*2+1] = true;
        marked[v] = false;
    }
}

void update(int v, int tl, int tr, int l, int r, ll new_val) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] = new_val;
        marked[v] = true;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), new_val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
    }
}

ll get(int v, int tl, int tr, int l,int r) {
	if(l>r)
		return 0;
    if (tl == tr) {
        return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    return get(v*2, tl, tm, l, min(r, tm))+
   	get(v*2+1, tm+1, tr, max(l, tm+1), r);
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
	// spre
	while(test--)
	{
		int n;
		cin>>n;
		int h[n];
		ll b[n];
		FOR(i,0,n)
		{
			cin>>h[i];
		}
		FOR(i,0,n)
		{
			cin>>b[i];
		}
		FOR(i,1,n)
		{
			if(b[i]<0 && b[i-1]<0)
			{
				if(h[i]>h[i-1])
				{
					b[i]=b[i-1];
					h[i]=h[i-1];
				}
				b[i-1]=0;
				h[i-1]=n+1;
			}
		}
		stack<ll> k;
		ll prev[n],next[n];
		FOR(i,0,n)
		{
			update(1,0,n,i,i,b[i]);
		}
		FOR(i,0,n)
		{
			while(!k.empty() && h[k.top()]>h[i])
			{
				next[k.top()]=i;
				k.pop();
			}
			k.push(i);
		}
		while(!k.empty())
		{
			next[k.top()]=-1;
			k.pop();
		}
		pair<ll,int> fuk[n];
		FORD(i,n,0)
		{
			fuk[i]=mp(h[i],i);
			while(!k.empty() && h[k.top()]>h[i])
			{
				prev[k.top()]=i;
				k.pop();
			}
			k.push(i);
		}
		while(!k.empty())
		{
			prev[k.top()]=-1;
			k.pop();
		}
		int o,y,i;
		sort(fuk,fuk+n,greater<pair<ll,int> >());
		FOR(j,0,n)
		{
			i=fuk[j].ss;
			if(b[i]<0)
			{
				o=next[i];
				y=prev[i];
				if(o!=-1 && get(1,0,n,i,next[i]-1)<0)
				{
					if(y!=-1 && get(1,0,n,prev[i]+1,i)<0)
					{
						if(get(1,0,n,i,next[i]-1)<get(1,0,n,prev[i]+1,i))
						{
							update(1,0,n,i,next[i]-1,0);
							update(1,0,n,next[i],next[i],b[next[i]]);
						}
						else
						{
							update(1,0,n,prev[i]+1,i,0);
							update(1,0,n,prev[i],prev[i],b[prev[i]]);
						}
					}
					else
					{
						update(1,0,n,i,next[i]-1,0);
							update(1,0,n,next[i],next[i],b[next[i]]);
					}
				}
				else
				{
					if(y!=-1 && get(1,0,n,prev[i]+1,i)<0)
					{
						update(1,0,n,prev[i]+1,i,0);
							update(1,0,n,prev[i],prev[i],b[prev[i]]);
					}
				}
			}
		}
		cout<<get(1,0,n,0,n)<<'\n';
	}
	return 0;
}