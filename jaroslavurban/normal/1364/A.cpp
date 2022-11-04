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
		int n,x;cin>>n>>x;
		vector<int>nums(n);
		int mn=n+1,mx=-1;
		ll sm=0;
		for(int i=0;i<n;++i){
			cin>>nums[i];
			sm+=nums[i];
			if(nums[i]%x){
				mn=min(i,mn);
				mx=max(i,mx);
			}
		}
		if(sm%x)cout<<n<<endl;
		else if(mn!=n+1)cout<<n-min(mn+1,n-mx)<<endl;
		else cout<<-1<<endl;
	}
}