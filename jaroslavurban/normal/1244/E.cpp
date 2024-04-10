#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

const int N=100010;
ll n,k;
ll a[N];
ll pr[N],su[N];
ll getmn(ll k){
	ll l=0,r=n-1;
	while(l<r){
		ll m=(l+r+1)/2;
		if(pr[m]<=k)l=m;
		else r=m-1;
	}
	return a[l]+(k-pr[l])/(l+1);
}
ll getmx(ll k){
	ll l=0,r=n-1;
	while(l<r){
		ll m=(l+r+1)/2;
		if(su[m]<=k)r=m-1;
		else l=m;
	}
//	cerr<<k<<" "<<r+1<<" "<<su[r+1]<<endl;
//	cerr<<a[r+1]-(k-su[r+1])/(n-(r+1))<<endl;
	return a[r+1]-(k-su[r+1])/(n-(r+1));
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>k;
	for(int i=0;i<n;++i)cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<n;++i)pr[i]=pr[i-1]+(a[i]-a[i-1])*i;
	for(int i=n-2;i>=0;--i)su[i]=su[i+1]+(a[i+1]-a[i])*(n-(i+1));
//	for(int i=0;i<n;++i)cerr<<su[i]<<" ";cerr<<endl;
	ll res=1e9;
	for(int i=0;i<n&&pr[i]<=k;++i)res=min(res,max(0ll,getmx(k-pr[i])-a[i]));
	for(int i=n-1;i>=0&&su[i]<=k;--i)res=min(res,max(0ll,a[i]-getmn(k-su[i])));
	cout<<res<<endl;
}