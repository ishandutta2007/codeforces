#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;
string s;
struct node
{
	int a=0,t=0,g=0,c=0;
};
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
		}
		a=(a*a);
		b>>=1;
	}
	return re;
}
node t[55][400001];
int con[11]={0,0,1,3,6,10,15,21,28,36,45};
node che(int i, int q,int b)
{
	node h;
	if(i%q!=b)
	return h;
	if(s[i]=='A')
	h.a++;
	else if(s[i]=='T')
	h.t++;
	else if(s[i]=='G')
	h.g++;
	else
	h.c++;
	return h;
}
node add(node a,node b)
{
	node h;
	h.a=a.a+b.a;
	h.c=a.c+b.c;
	h.g=a.g+b.g;
	h.t=a.t+b.t;
	return h;
}
void build(int v, int tl, int tr,int q,int b) {
	int f=con[q]+b;
    if (tl == tr) {
        t[f][v] = che(tl,q,b);
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm,q,b);
        build(v*2+1, tm+1, tr,q,b);
        t[f][v] = add(t[f][v*2] , t[f][v*2+1]);
    }
}
node sum(int v, int tl, int tr, int l, int r,int q,int b) {
	int f=con[q]+b;
    if (l > r) 
        {
        	node z;
        	return z;
		}
    if (l == tl && r == tr) {
        return t[f][v];
    }
    int tm = (tl + tr) / 2;
    return add(sum(v*2, tl, tm, l, min(r, tm),q,b),sum(v*2+1, tm+1, tr, max(l, tm+1), r,q,b));
}
void update(int v, int tl, int tr, int pos,int q,int b) {
	int f=con[q]+b;
    if (tl == tr) {
        t[f][v] = che(tl,q,b);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos,q,b);
        else
            update(v*2+1, tm+1, tr, pos,q,b);
        t[f][v] = add(t[f][v*2] , t[f][v*2+1]);
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		cin>>s;	
		int n=s.size();
		FOR(i,1,11)
		{
			FOR(j,0,i)
			{
				build(1,0,n-1,i,j);
			}
		}
		int q;
		cin>>q;
		int t,l,r,x;
		string o;
		char c;
		FOR(i,0,q)
		{
			cin>>t;
			if(t==1)
			{
				cin>>x>>c;
				x--;
				s[x]=c;
				FOR(j,1,11)
				{
					update(1,0,n-1,x,j,x%j);
				}
			}
			else
			{
				cin>>l>>r>>o;
				int d=o.size();
				int q=(l-1)%d;
				node h;
				int ans=0;
				FOR(i,0,d)
				{
					h=sum(1,0,n-1,l-1,r-1,d,(q+i)%d);
					if(o[i]=='A')
					ans+=h.a;
					else if(o[i]=='T')
					ans+=h.t;
					else if(o[i]=='G')
					ans+=h.g;
					else
					ans+=h.c;
//					cout<<h.a<<' '<<h.c<<' '<<h.g<<' '<<h.t<<o[i]<<'\n';
				}
				cout<<ans<<'\n';
			}
		}
	}
	return 0;
}