#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(w) (ll) w.size()
#define frx(x,z,y) for(ll x=z;x<y;++x)
#define fr(x,y) frx(x,0,y)
#define inf 9e18+1
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);


vector<ll> nums;
vector<ll> len;
ll mx;
void getl(ll idx){
	ll num=nums[idx];
	for(ll i=1;i*i<=idx+1;++i){
		if((idx+1)%(i)==0){
			if(num>nums[(idx+1)/i-1])
				len[idx]=max(len[idx],len[(idx+1)/i-1]+1);
			if(num>nums[i-1])
				len[idx]=max(len[idx],len[i-1]+1);
		}
	}
	mx=max(mx,len[idx]);
}


int main(){
	ll t;cin>>t;
	fr(i,t){
		ll n;cin>>n;	
		nums.resize(n);
		fr(i,n){
			ll num;cin>>num;nums[i]=num;
		}
		mx=1;
		len.assign(n,1);
		len[0]=1;
		frx(i,1,n)getl(i);
		cout<<mx<<endl;
////////////////		fr(i,n)cout<<len[i]<<" ";
//		cout<<endl;
	}
}