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
	for(ll tc=0;tc<t;++tc){
		ll a,b;cin>>a>>b;
		ll cnt=0;
		while(a<b){
			++cnt;
			if(8*a<=b)a*=8;
			else if(4*a<=b)a*=4;
			else a*=2;
		}
		bool pos=true;
		while(a>b){
			++cnt;
			if(a/8>=b&&a%8==0)a/=8;
			else if(a/4>=b&&a%4==0)a/=4;
			else if(a%2==0)a/=2;
			else {
				pos=false;
				break;
			}
		}
		if(pos&&a==b)cout<<cnt<<endl;
		else cout<<-1<<endl;
	}
}