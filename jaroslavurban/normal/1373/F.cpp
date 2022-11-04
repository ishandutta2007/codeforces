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
#define int ll

const int N=1000010;
int a[N],b[N],f[N],fb[N];
main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	int t;cin>>t;
	for(int tc=0;tc<t;++tc){
		int n;cin>>n;
		ll sm=0;
		for(int i=0;i<n;++i){cin>>a[i];sm+=a[i];}
		for(int i=0;i<n;++i){cin>>b[i];sm-=b[i];}
		if(sm>0){
			cout<<"NO\n";
			continue;
		}
		bool pos=true;
		f[1]=min(b[0],a[1]);
		b[0]=max(0ll,b[0]-a[1]);
		for(int i=1;i<n-1;++i){
			fb[i]=f[i];
			if(f[i]!=a[i]){
				if(a[i]-f[i]>b[i])pos=false;
				b[i]-=a[i]-f[i];
				f[i]=a[i];
			}
			f[i+1]=min(b[i],a[i+1]);
			b[i]=max(0ll,b[i]-a[i+1]);
		}

		int i=n-1;
		fb[i]=f[i];
		if(f[i]!=a[i]){
			if(a[i]-f[i]>b[i])pos=false;
			b[i]-=a[i]-f[i];
			f[i]=a[i];
		}
		f[0]=min(b[i],a[0]);
		b[i]=max(0ll,b[i]-a[0]);

		if(a[0]-f[0]>b[0]){
			for(int i=n-1;i>=1;--i){
				int giving=min(fb[i],b[i]);
				b[i]-=giving;
				b[i-1]+=giving;
			}
		}
		if(a[0]-f[0]>b[0])pos=false;
		if(pos)cout<<"YES\n";
		else cout<<"NO\n";;
	}
}