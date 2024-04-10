#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);

const int N=200100,offset=100010;
bool a[N];
int rr[N],n;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n;
		int mn=1e9;
		for(int i=0;i<2*n;++i){
			int j;cin>>j;a[i]=(j==1);
		}
		memset(rr,-1,sizeof(rr));
		for(int i=2*n-1,csm=0;i>=n-1;--i){
			rr[csm+offset]=i;
			if(a[i])++csm;
			else --csm;
		}
		int res=1e9;
		for(int i=0,csm=0;i<=n;++i){
			if(~rr[offset-csm])
				res=min(res,n-i+rr[offset-csm]-n+1);
			if(a[i])++csm;
			else --csm;
		}
		cout<<res<<endl;
	}
}