#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);

int main(){
	int t;cin>>t;
	while(t--){
		ll n,k;cin>>n>>k;
		vector<ll>a(n),f(k);
		for(int i=0;i<n;++i)cin>>a[i];
		for(int i=0;i<k;++i)cin>>f[i];
		sort(a.begin(),a.end());
		sort(f.begin(),f.end());
		reverse(f.begin(),f.end());
		ll sm=0;
		int i=0; // current num im giving
		for(ll cf=0;cf<k;++cf){
			if(f[cf]>1)sm+=a[i];
			i+=f[cf]-1;
		}
		for(int j=0;j<k;++j)if(f[j]!=1)sm+=a[i++];
		for(int j=0;j<k;++j)if(f[j]==1)sm+=2*a[i++];
		assert(i==n);
		cout<<sm<<endl;
	}
}