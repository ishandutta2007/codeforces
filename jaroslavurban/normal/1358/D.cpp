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
	ll n,x;cin>>n>>x;
	vector<ll>d(n);
	for(int l=0;l<n;++l)cin>>d[l];
	ll sm=0,bsm=0;
	ll dist=0;
	int p1=n-1;
	for(int i=n-1;i>=0;--i){
		if(p1==i){
			sm=0;
			dist=0;
		}
		while(dist+d[p1]<x){
			sm+=d[p1]*(d[p1]+1)/2;
			dist+=d[p1];
			p1=(p1-1+n)%n;
		}
		ll sma=sm+(x-dist)*d[p1]-(x-dist)*(x-dist-1)/2;
		//cout<<sm<<endl;
		bsm=max(sma,bsm);
		sm-=d[i]*(d[i]+1)/2;
		dist-=d[i];
		//cout<<i<<" "<<p1<<" "<<dist<<endl;
		if(p1==i){
			dist=0;
			p1=(p1-1+n)%n;
			sm=0;
		}
	}
	cout<<bsm<<endl;
}