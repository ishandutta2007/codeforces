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

const int N=100100;
int main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int n;cin>>n;
	int a[N];
	for(int i=0;i<n;++i)cin>>a[i];
	sort(a,a+n);
	ll aa=0,bb=0;
	for(int i=0;i<n;++i)if(i<n/2)aa+=a[i];else bb+=a[i];
	cout<<aa*aa+bb*bb<<endl;
}