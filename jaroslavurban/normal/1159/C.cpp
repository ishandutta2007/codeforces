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
ll a[N],b[N];
int main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<m;++i)cin>>b[i];
	sort(a,a+n);
	sort(b,b+m);
	if(a[n-1]>b[0]){cout<<-1<<endl;return 0;}
	ll res=0;
	for(int i=0;i<n;++i)res+=a[i]*m;
	if(b[0]!=a[n-1])res+=b[0]-a[n-2];
	for(int i=(b[0]!=a[n-1]);i<m;++i)res+=b[i]-a[n-1];
	cout<<res<<endl;
}