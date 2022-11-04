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
		ll d2=0,d3=0;
		while(n%3==0){++d3;n/=3;}
		while(n%2==0){++d2;n/=2;}
		if(n!=1)cout<<-1<<endl;
		else if(d3>=d2)cout<<2*(d3-d2)+d2<<endl;
		else cout<<-1<<endl;
	}
}