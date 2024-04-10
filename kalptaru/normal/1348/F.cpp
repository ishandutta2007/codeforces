#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
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
			re%=mod;
		}
		a=(a*a);
		a%=mod;
		b>>=1;
	}
	return re;
}
struct arr
{
	int i;
	int a,b;
};
bool che(arr a,arr b)
{
	if(a.a==b.a)
	return a.b<b.b;
	return a.a<b.a;
}
pair<int,int> t[800100];
void update(int v, int tl, int tr, int pos, int new_val,int p) {
    if (tl == tr) {
        t[v]=mp(new_val,p);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val,p);
        else
            update(v*2+1, tm+1, tr, pos, new_val,p);
        t[v]=min(t[2*v],t[2*v+1]);
    }
    return;
}
pair<int,int> sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return mp(1000000,0);
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(sum(v*2, tl, tm, l, min(r, tm)), sum(v*2+1, tm+1, tr, max(l, tm+1), r));
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
		arr a[n];
		int backup[n];
		FOR(i,0,n)
		{
			cin>>a[i].a>>a[i].b;
			a[i].i=i;
			backup[i]=a[i].a;
		}
		sort(a,a+n,che);
		pair<int,int> u;
		set< pair<int,int> > fil;
		int ar[n],br[n];
		int j=0;
		FOR(i,0,n)
		{
			while(j<n && a[j].a==i+1)
			{
				fil.insert(mp(a[j].b,a[j].i));
				j++;
			}
			u=*fil.begin();
			fil.erase(u);
			ar[u.second]=i+1;
			br[u.second]=i+1;
			update(1,0,n,i+1,backup[u.second],u.second);
//			cout<<'t';
		}
		
		bool f=0;
//		cout<<'k';
		FOR(i,0,n)
		{
//			cout<<a[i].i+1<<' '<<a[i].b<<'\n';
			u=sum(1,0,n,ar[a[i].i]+1,a[i].b);
//			cout<<u.first<<' ';
			if(u.first<=ar[a[i].i])
			{
//				cout<<i<<' ';
				swap(br[a[i].i],br[u.second]);
				f=1;
				break;
			}
		}
		if(f)
		{
			cout<<"NO\n";
			FOR(i,0,n)
			cout<<ar[i]<<' ';
			cout<<'\n';
			FOR(i,0,n)
			cout<<br[i]<<' ';
		}
		else
		{
			cout<<"YES\n";
			FOR(i,0,n)
			cout<<ar[i]<<' ';
		}
	}
	return 0;
}