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
	for(int tc=0;tc<t;++tc){
		int n;cin>>n;
		vector<int>a(n);
		vector<int>b(n);
		for(int i=0;i<n;++i)cin>>a[i];
		for(int i=0;i<n;++i)cin>>b[i];
		multiset<set<int>>m;
		multiset<set<int>>m2;
		for(int i=0;i<n/2;++i)m.insert(set<int>{b[i],b[n-i-1]});
		for(int i=0;i<n/2;++i)m2.insert(set<int>{a[i],a[n-i-1]});
		if(m!=m2||(n%2&&a[n/2]!=b[n/2]))cout<<"No\n";
		else cout<<"Yes\n";
	}
}