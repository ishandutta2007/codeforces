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
	int tt;cin>>tt;
	for(int tc=0;tc<tt;++tc){
		int n;cin>>n;
		vector<pair<ll,ll>>s(2*n);
		for(int i=0;i<2*n;++i){
			cin>>s[i].first;
			s[i].second=i;
		}
		vector<int>ncovered(n);
		sort(s.begin(),s.end());
		set<int>a;
		ll lands=0;
		int uncovered=0;
		for(int i=0;i<2*n;){
			bool ended=false;
			do{
				if(s[i].second%2==0)a.insert(s[i].second/2);
				else {
					a.erase(s[i].second/2);
					ended=true;
				}
				++i;
			}		
			while(i<2*n&&s[i-1].first==s[i].first);
//			cerr<<i-1<<" this num: "<<s[i-1].first<<" started: "<<started.size()<<" size: "<<a.size()<<endl;
			if(ended&&a.size()==1&&i<2*n&&(s[i].second/2!=*a.begin()||(i+1<2*n&&s[i+1].first==s[i].first)))
				uncovered=max(uncovered,++ncovered[*a.begin()]);
			lands+=!a.size();
		}
		if(uncovered)cout<<lands+uncovered<<endl;
		else{
			bool con=false;
			for(int i=0;i<2*n-1;++i)
				if(s[i].second%2==s[i+1].second%2||(s[i].second%2&&s[i].first==s[i+1].first))
					con=true;
			cout<<lands-!con<<endl;
		}
	}
}