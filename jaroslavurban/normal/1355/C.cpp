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
	int a,b,c,d;
	ll res=0;
	cin>>a>>b>>c>>d;
	int n=c-a+1;
	vector<ll>ways(n); //0==a+b
	for(int i=0;i<b-a+1;++i){
		ways[i]+=1;
		int r=i+c-b+1;
		if(r<n)ways[r]-=1;
	}
	for(int i=1;i<n;++i)
		ways[i]+=ways[i-1];
	for(int i=n-2;i>=0;--i)
		ways[i]+=ways[i+1];
	for(int i=0;i<d-c+1;++i){
		int r=max(0,c+i-a-b+1);
		if(r<n)res+=ways[r];
	}
//	for(int i=0;i<n;++i)cout<<ways[i]<<" ";
//		cout<<endl;
	cout<<res<<endl;
}