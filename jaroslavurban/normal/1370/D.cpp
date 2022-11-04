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

ll n,k;
vector<ll>a;
int main(){
	cin>>n>>k;
	a.resize(n);
	for(int i=0;i<n;++i)cin>>a[i];
	ll l=1,r=10000000000;
	while(l<r){
		ll m=(l+r)/2;
		ll cnt=0;
		for(int i=0;i<n;++i)
			if(a[i]<=m){cnt+=1+(i!=n-1);++i;}
		ll cnt2=1;
		for(int i=1;i<n;++i)
			if(a[i]<=m){cnt2+=1+(i!=n-1);++i;}
		bool pos=cnt>=k||cnt2>=k;
//		cerr<<m<<" "<<pos<<" "<<cnt<<" "<<cnt2<<endl;
		if(pos)r=m;
		else l=m+1;
	}
	cout<<l<<endl;
}