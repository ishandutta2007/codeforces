#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

const int N=512;
int a[N],b[N];
int n,m;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<m;++i)cin>>b[i];

	for(int i=0;i<N;++i){
		bool p=true;
		for(int j=0;j<n;++j){
			bool pos=false;
			for(int k=0;k<m;++k)
				if((a[j]&b[k])<=i&&(~i&a[j]&b[k])==0)
					pos=true;
			p&=pos;
		}
		if(p){cout<<i<<endl;break;}
	}
}