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
	string s;cin>>s;
	int l=0,r=s.size()-1;
	vector<int>res;
	while(l<r){
		while(l<r&&s[l]!='(')++l;
		while(l<r&&s[r]!=')')--r;
		if(l<r){
			res.push_back(l);
			res.push_back(r);
		}
		++l;--r;
	}
	sort(res.begin(),res.end());
	cout<<(res.size()?1:0)<<endl;
	if(res.empty())return 0;
	cout<<res.size()<<endl;
	for(auto r:res)cout<<r+1<<" ";
	cout<<endl;
}