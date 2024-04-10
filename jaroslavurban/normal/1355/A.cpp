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

const int N=200001;
int a[N];
ll getmn(ll a){
	ll mn=a%10;
	while(a/=10)mn=min(a%10,mn);
	return mn;
}
ll getmx(ll a){
	ll mx=a%10;
	while(a/=10)mx=max(a%10,mx);
	return mx;
}
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		ll a,k;cin>>a>>k;--k;
		ll mn,mx;
		while(k--&&getmn(a))a+=getmn(a)*getmx(a);
		cout<<a<<endl;
	}
}