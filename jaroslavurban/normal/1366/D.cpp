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

const ll N=500010;
const ll M=10000001;
ll erat[M];
ll a[N],b[N];
int main(){
	erat[0]=erat[1]=1;
	for(ll i=2;i<M;++i){
		if(!erat[i]){
			erat[i]=i;
			for(ll j=i*i;j<M;j+=i)erat[j]=i;
		}
	}
	ll n;cin>>n;
	for(ll tc=0;tc<n;++tc){
		ll val;cin>>val;
		ll d1=0,d2=1;
		for(ll d=erat[val];d!=1;val/=d,d=erat[val])
			if(!d1)d1=d;
			else if(d!=d1)d2*=d;
		if(d2==1)a[tc]=b[tc]=-1;
		else{
			a[tc]=d1;
			b[tc]=d2;
		}
	}
	for(ll i=0;i<n;++i)cout<<a[i]<<" ";
	cout<<endl;
	for(ll i=0;i<n;++i)cout<<b[i]<<" ";
	cout<<endl;
}