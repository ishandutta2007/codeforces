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

const int q=13;
int main(){
	int n;cin>>n;
	vector<int>masks(n);
	vector<ll>qres(q,0);
	vector<vector<int>>qidx(q);// [query number][ith element of the query]
	int cnt=0;
	for(int i=0;i<(1<<q);++i){
		if(__builtin_popcount(i)!=q/2)continue;
		masks[cnt++]=i;
		for(int j=0;j<q;++j)
			if(!(i&(1<<j)))
				qidx[j].push_back(cnt);
		if(cnt==n)break;
	}
	for(int i=0;i<q;++i)
		if(qidx[i].size()){
			cout<<"? "<<qidx[i].size();
			for(auto idx:qidx[i])cout<<" "<<idx;
			cout<<endl;
			cin>>qres[i];
		}
	cout<<"!";
	for(auto m:masks){
		ll res=0;
		for(int i=0;i<q;++i)
			if(m&(1<<i))
				res|=qres[i];
		cout<<" "<<res;
	}
	cout<<endl;
}