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
		int n;cin>>n;
		vector<int>a(n);
		vector<bool>used(n),signs(n);
		for(int i=0;i<n;++i){cin>>a[i];a[i]=abs(a[i]);}
		bool plus=true;
		for(int j=0;j<110;++j){
			for(int i=1;i<n-1;++i)
				if(a[i-1]<=a[i]&&a[i]>=a[i+1]&&!used[i-1]&&!used[i]){
					signs[i]=plus;
					used[i-1]=true;
					used[i]=true;
				}
			for(int i=0;i<n-1;++i)
				if((!i||used[i-1])&&a[i]>=a[i+1]&&!used[i]){
					signs[i]=plus;
					plus=!plus;
					used[i]=true;
				}
			for(int i=1;i<n;++i)
				if((i+1==n||used[i])&&a[i-1]<=a[i]&&!used[i-1]){
					signs[i]=!plus;
					plus=!plus;
					used[i-1]=true;
				}
		}
		for(int i=0;i<n;++i)cout<<(signs[i]?-1:1)*a[i]<<" ";
		cout<<endl;
	}
}