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
 
const int N=1001;
int a[N],n;
int getmex(){
	bool is[N]={};
	for(int i=0;i<n;++i)if(a[i]<n)is[a[i]]=true;
	for(int i=0;i<n;++i)if(!is[i])return i;
	return n;
}
int main(){
	int t;cin>>t;
	for(int tc=0;tc<t;++tc){
		cin>>n;
		for(int i=0;i<n;++i)cin>>a[i];
		int k=0;
		vector<int>res;
		while(1){
			int mx=getmex();
			if(mx==n){
				bool found=false;
				for(int i=0;i<n;++i)
					if(a[i]!=i){
						a[i]=mx;
						found=true;
						res.push_back(i);
						break;
					}
				if(!found)break;
			}
			else{
				a[mx]=mx;
				res.push_back(mx);
			}
		}
		cout<<res.size()<<endl;
		for(auto x:res)cout<<x+1<<" ";
		cout<<endl;
	}
}