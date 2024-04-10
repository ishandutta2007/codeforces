#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(w) (ll) w.size()
#define fr(x,y) for(ll x=0;x<y;++x)
#define frx(x,y,z) fr(x,0,y)
#define inf 9e18+1
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);

int main(){
	ll t;cin>>t;
	fr(i,t){
		ll n,k;cin>>n>>k;
		ll div;
		for(ll j=2;j<=n;++j)
			if(n%j==0){
				div=j;
				break;
			}
		cout<<n+div+(k-1)*2<<endl;
	}
}