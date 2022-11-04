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
 
const int N=1010;
int a[N];
int main(){
	int n;cin>>n;
	vector<pair<int,pair<int,int>>>s;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			if(a[i]>a[j])
				s.push_back({-j,{a[i],i}});
	sort(s.begin(),s.end());
	cout<<s.size()<<endl;
	for(auto e:s)
		cout<<e.second.second+1<<" "<<-e.first+1<<endl;
}