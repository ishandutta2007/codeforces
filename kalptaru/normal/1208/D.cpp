#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
#define pb(a) push_back(a);
ll t[1000000];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = tl+1;
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
int sum(int v, int tl, int tr, ll r) {
	int tm = (tl + tr) / 2;
	if(tl==tr)
		return tr;
    if (t[2*v]>r) 
        return sum(2*v,tl,tm,r);
    if (t[2*v]<=r) 
        return sum(2*v+1,tm+1,tr,r-t[2*v]);
}
void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        t[v] = 0;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos);
        else
            update(v*2+1, tm+1, tr, pos);
        t[v] = t[v*2] + t[v*2+1];
    }
}
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	int t=1;
//	cin>>t;
//	while(t--)
//	{
		ll n;
		cin>>n;
		ll s[n];
		int ans[n];
		FOR(i,0,n)
		cin>>s[i];
		build(1,0,n-1);
//		update(1,0,n-1,2);
//		FOR(i,0,40)
//		cout<<t[i]<<' ';
		int d;
		FOR(i,1,n+1)
		{
			ans[n-i]=sum(1,0,n-1,s[n-i])+1;
			update(1,0,n-1,ans[n-i]-1);
		}
		FOR(i,0,n)
		cout<<ans[i]<<' ';
//	}
}