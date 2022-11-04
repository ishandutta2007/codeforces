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
		string s;cin>>s;
		int n=s.size();
		int priceoneleft[1001]={};
		int pricezeroleft[1001]={};
		priceoneleft[0]=s[0]=='0';
		pricezeroleft[0]=s[0]=='1';
		for(int i=1;i<n;++i){
			priceoneleft[i]+=priceoneleft[i-1];
			priceoneleft[i]+=s[i]=='0';
			pricezeroleft[i]+=pricezeroleft[i-1];
			pricezeroleft[i]+=s[i]=='1';
		}
		int priceoneright[1001]={};
		int pricezeroright[1001]={};
		priceoneright[n-1]=s[n-1]=='0';
		pricezeroright[n-1]=s[n-1]=='1';
		for(int i=n-2;i>=0;--i){
			priceoneright[i]+=priceoneright[i+1];
			priceoneright[i]+=s[i]=='0';
			pricezeroright[i]+=pricezeroright[i+1];
			pricezeroright[i]+=s[i]=='1';
		}
		int bst=100000;
		for(int i=0;i<n+1;++i){
			int pr=0;
			if(i-1>=0)pr+=priceoneleft[i-1];
			if(i<n)pr+=pricezeroright[i];
			bst=min(bst,pr);
		}
		for(int i=0;i<n+1;++i){
			int pr=0;
			if(i-1>=0)pr+=pricezeroleft[i-1];
			if(i<n)pr+=priceoneright[i];
			bst=min(bst,pr);
		}
		cout<<bst<<endl;
	}
}