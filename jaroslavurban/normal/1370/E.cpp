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

ll n;
string s,t;
int main(){
	cin>>n>>s>>t;
	ll h0=0,h1=0;
	ll h0mx=0,h1mx=0;
	ll c=0;
	for(int i=0;i<n;++i){
		if(s[i]==t[i])continue;
		if(s[i]=='1'){
			++c;
			++h0;--h1;
			h1=max(0ll,h1);
		}
		else{
			--c;
			++h1;--h0;
			h0=max(0ll,h0);
		}
		h0mx=max(h0,h0mx);
		h1mx=max(h1,h1mx);
	}
	if(c!=0)cout<<-1<<endl;
	else cout<<max(h0mx,h1mx)<<endl;
}