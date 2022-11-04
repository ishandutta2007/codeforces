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
		int n,k,d;cin>>n>>k>>d;
		vector<int>s(n);
		for(int i=0;i<n;++i)cin>>s[i];
		int cnt=0;
		map<int,int>sm;
		for(int i=0;i<d;++i)
			if(!sm[s[i]]++)++cnt;
		int bcnt=cnt;
		for(int i=1;i+d<=n;++i){
			if(!--sm[s[i-1]])--cnt;
			if(!sm[s[i+d-1]]++)++cnt;
			bcnt=min(bcnt,cnt);
		}
		cout<<bcnt<<endl;
	}
}