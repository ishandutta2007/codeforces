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
	ll t;cin>>t;
	while(t--){
		ll n;cin>>n;
		ll odd=-1;
		ll oddi=0;
		ll even=-1;
		ll ei=0;
		ll cnt=0;
		for(int i=0;i<2*n;++i){
			ll a;cin>>a;
			if(cnt!=n-1)
				if(a%2){
					if(odd!=-1){
						cout<<oddi+1<<" "<<i+1<<endl;
						odd=-1;++cnt;
					}
					else{
						odd=a;oddi=i;
					}
				}
				else{
					if(even!=-1){
						cout<<ei+1<<" "<<i+1<<endl;
						even=-1;++cnt;
					}
					else{
						even=a;ei=i;
					}
				}
		}
	}
}