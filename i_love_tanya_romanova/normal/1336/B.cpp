
#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
 
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vpll vector < pair<long long,long long> >
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define fill(a)  memset(a, 0, sizeof (a))
#define mp make_pair
#define pb push_back
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define pdd pair<double, double>
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define forstl(i,v) for(auto &i: v)
#define dbg(x) cout << #x << " = " << x << '\n'
#define dbg2(x,y) cout<<#x<<" = "<<x<<" & "<<#y<<" = "<<y<<endl
#define dbgstl(v) cout<<#v<<" = \n"; { int c=0; forstl(it,v) \
cout<<"    "<<#v<<"["<< ++c <<"] = "<<it<<endl;} cerr<<endl
#define dbgstlp(v) cout<<#v<<" = \n"; { int c=0; forstl(it,v) \
cout<<"    "<<#v<<"["<< ++c <<"] = "<<it.f<<" , "<<it.s<<endl;} cerr<<endl
#define PI           3.14159265358979323846
 
#define rep(i, n)    for(i = 0; i < (n); ++i)
#define repA(i, a, n)  for(i = a; i <= (n); ++i)
#define repD(i, a, n)  for(i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define pdd pair<double, double>
#define in(v,n) vll v(n);rep(i,n) cin>>v[i]
 
// v.back() to get the value of last element
 
using namespace std;
 
ll gd(ll a,ll b,ll c){
	// dbg2(a,b);
	ll a1 = (a-b)*(a-b) + (a-c)*(a-c) + (c-b)*(c-b);
	// dbg2(c,a1);
	return (a-b)*(a-b) + (a-c)*(a-c) + (c-b)*(c-b);
}
 
// vll vr;
// vll vg;
// vll vb;
 
ll chk(ll a, vll &v1,vll &v2){
	ll ans;
	{
		// For v1 first
		auto it = lower_bound(all(v1),a); if(it==v1.end()) it--;
		ll b = *it;
		ll c = (a+b+1)/2;
		it = lower_bound(all(v2),c); if(it==v2.end()) it--; 
		ans = gd(a,b,*it);
		if (it!=v2.begin())--it;
		ans =min(ans,gd(a,b,*it));
		// cout<<1<<endl;
	}
	return ans;
}
 
 
 
 
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    int T;
    // cout<<std::fixed<<std::setprecision(35);
    cin>>T;while(T--)
	{
		ll t,n,i,j,x,y,m,l,d,k;
		ll nr,ng,nb;
		cin>>nr>>ng>>nb;
		in(vr,nr);
		in(vg,ng);
		in(vb,nb);
 
		// vr.resize(nr);
		// vg.resize(ng);
		// vb.resize(nb);
		// rep(i,nr) cin>>vr[i];
		// rep(i,ng) cin>>vg[i];
		// rep(i,nb) cin>>vb[i];
 
		sort(all(vr));
		sort(all(vg));
		sort(all(vb));
 
		ll ans = gd(vr[0],vg[0],vb[0]);
 
		for(auto it:vr){
			ans = min(ans,chk(it,vg,vb));
			ans = min(ans,chk(it,vb,vg));
		}
		// dbg(ans);
		for(auto it:vg){
			ans = min(ans,chk(it,vr,vb));
			ans = min(ans,chk(it,vb,vr));
		}
		for(auto it:vb){
			ans = min(ans,chk(it,vg,vr));
			ans = min(ans,chk(it,vr,vg));
		}
 
 
 
		cout<<ans<<endl;
		// vr.clear();
		// vg.clear();
		// vb.clear();
	}
}