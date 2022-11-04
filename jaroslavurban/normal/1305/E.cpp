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
	ll n,m;cin>>n>>m;
	ll sm=0;
	vector<int>res;
	bool done=false;
	for(int i=0;i<n;++i){
		if(sm+i/2<=m){
			sm+=i/2;
			res.push_back(i+1);
		}
		else if(!done&&sm!=m){
			res.push_back(i-1+i-2*(m-sm)+2);
			sm=m;
			done=true;
		}
		else res.push_back(10000000+i*6000);
	}
	if(sm<m){
	cerr<<sm<<endl;
		cout<<-1<<endl;
		return 0;
	}
	for(auto e:res)cout<<e<<" ";
	cout<<endl;
}