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

int cnt[20];
int main(){
	ll n,res=0;;cin>>n;
	for(int i=0;i<n;++i){
		ll val;cin>>val;
		for(int j=0;j<20;++j)cnt[j]+=!!(val&(1<<j));
	}
	for(int i=0;i<n;++i){
		ll val=0;
		for(int j=0;j<20;++j)if(cnt[j]-->0)val|=(1<<j);
		res+=val*val;
	}
	cout<<res<<endl;
}