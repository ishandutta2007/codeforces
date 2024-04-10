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

#define inf 31

int main(){
	int n;cin>>n;
	vector<int>cards(n);
	for(int i=0;i<n;++i)cin>>cards[i];
	int bbsm=0;
	for(int num=1;num<31;++num){
		int bsm=0;
		int sm=0,mx=-inf;
		for(int i=0;i<n;++i){
			bool fl=false;
			if(mx<cards[i]){
				if((cards[i]==num&&mx!=num))fl=true;
				mx=cards[i];
			}
			if(!fl)sm+=cards[i];
			if(mx==num)bsm=max(sm,bsm);
			if((mx!=num&&(sm<0||mx>num))||(mx==num&&(sm+num<0||mx>num))){
				mx=-inf;
				sm=0;
			}
		}
		bbsm=max(bbsm,bsm);
	}
	cout<<bbsm<<endl;
}