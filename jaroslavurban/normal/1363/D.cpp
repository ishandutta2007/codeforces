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
		int n,k;cin>>n>>k;
		vector<set<int>>s(k);
		for(int i=0;i<k;++i){
			int sz;if(!(cin>>sz))return 0;
			for(int j=0;j<sz;++j){
				int num;if(!(cin>>num))return 0;s[i].insert(num);
			}
		}
		cout<<"? "<<n<<" ";
		for(int i=0;i<n;++i)cout<<i+1<<" ";
		int mx;if(!(cin>>mx)||mx==-1)return 0;
		int l=1,r=n+1;
		while(l+1<r){
			int m=(l+r)/2;
			cout<<"? "<<r-m<<" ";
			for(int i=m;i<r;++i)cout<<i<<" ";
			int res;cin>>res;if(res==-1)return 0;
			if(res==mx)l=m;
			else r=m;
		}
		int idx=-1,mx2=mx;
		for(int i=0;i<k;++i)if(s[i].count(l))idx=i;
		if(idx!=-1){
			cout<<"? "<<n-s[idx].size()<<" ";
			for(int i=0;i<n;++i)if(!s[idx].count(i+1))cout<<i+1<<" ";
			if(!(cin>>mx2)||mx2==-1)return 0;
		}
		cout<<"! ";
		for(int i=0;i<k;++i)
			if(i==idx)cout<<mx2<<" ";
			else cout<<mx<<" ";
		string str;cin>>str;if(str=="Incorrect")return 0;
	}
}