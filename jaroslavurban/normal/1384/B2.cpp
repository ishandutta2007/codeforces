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

const int N=300010;
ll n,k,l;
ll d[N];
int main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>k>>l;
		for(int i=0;i<n;++i)cin>>d[i];
		d[n]=0;
		int safepoint=-1;
		while(safepoint!=n){
			int prevs=safepoint;
			ll kk=k;
			bool down=true;
			for(int i=safepoint+1;i<=n;++i){
				if(i==n)safepoint=n;
				if(d[i]+k<=l)safepoint=i;
				if(d[i]+kk>l&&(!down||d[i]>l))break;
				if(d[i]+kk>l)kk=l-d[i];
				if(!kk)down=false;
				if(down)--kk;
				else ++kk;
				if(kk<=0)down=false;
			}
			if(prevs==safepoint)break;
		}
		if(safepoint==n)cout<<"Yes\n";
		else cout<<"No\n";
	}
}