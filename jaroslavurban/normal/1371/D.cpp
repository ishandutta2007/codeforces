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
	for(int tc=0;tc<t;++tc){
		ll n,k;cin>>n>>k;
		vector<vector<bool>>f(n,vector<bool>(n,0));
		ll cnt=0;
		for(int i=0;i<n&&cnt<k;++i)
			for(int j=i;j<i+n&&cnt<k;++j)
				f[j%n][(j-i)%n]=++cnt;
		ll mnr=1000000000,mnc=100000000,mxr=0,mxc=0;
		for(int i=0;i<n;++i){
			ll c=0;
			for(int j=0;j<n;++j)
				if(f[i][j])++c;
			mnr=min(c,mnr);mxr=max(c,mxr);
		}
		for(int i=0;i<n;++i){
			ll c=0;
			for(int j=0;j<n;++j)
				if(f[j][i])++c;
			mnc=min(c,mnc);mxc=max(c,mxc);
		}
		cout<<pow(mxr-mnr,2)+pow(mxc-mnc,2)<<endl;
		for(int i=0;i<n;++i,cout<<endl)for(int j=0;j<n;++j)cout<<f[i][j];
	}
}