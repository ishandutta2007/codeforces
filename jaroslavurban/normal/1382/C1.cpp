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
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		string s,t;cin>>s>>t;
		vector<int>res;
		for(int i=n-1;i>=0;--i){
			if(s[i]==t[i])continue;
			if(s[i]!=s[0])res.push_back(0);
			res.push_back(i);
			reverse(s.begin(),s.begin()+i+1);
			for(int j=0;j<n-1;++j)if(s[j]=='1')s[j]='0';else s[j]='1';
		}
		cout<<res.size()<<" ";
		for(auto o:res)cout<<o+1<<" ";
		cout<<endl;
	}
}