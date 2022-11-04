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
#define inf int(1e9)

int n,p;
const int N=100010;
int a[N];

bool is(int candies,bool wantpos){
	int idx=0;
	bool pos=true,isp=false;
	for(int c=candies;idx<n&&c<candies+n;++c){
		for(;idx<n&&c>=a[idx];++idx){}
		if(idx<=c-candies)pos=false;
		if(idx-(c-candies)>=p)isp=true;
	}
	if(wantpos)return pos;
	return isp;
}

int main(){
	cin>>n>>p;
	for(int i=0;i<n;++i)cin>>a[i];
	sort(a,a+n);
	int l=1,r=inf+1;
	while(l<r){
		int mid=(l+r)/2;
		if(is(mid,false))r=mid;
		else l=mid+1;
	}
	int mx=l,mn;
//	cerr<<mx<<endl;
	l=1,r=inf+1;
	while(l<r){
		int mid=(l+r)/2;
		if(is(mid,true))r=mid;
		else l=mid+1;
	}
	mn=l;
//	cerr<<mn<<endl;
	cout<<max(0,mx-mn)<<endl;
	for(int i=mn;i<mx;++i)cout<<i<<" ";
	cout<<endl;
}