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

int n,m,y,x;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m>>y>>x;
	cout<<y<<" "<<x<<"\n1 "<<x<<endl;
	for(int i=1;i<=n;++i)
		if(i%2){for(int j=1;j<=m;++j)
			if((i!=y||j!=x)&&(i!=1||j!=x))cout<<i<<" "<<j<<endl;
		}
		else for(int j=m;j>=1;--j)
			if((i!=y||j!=x)&&(i!=1||j!=x))cout<<i<<" "<<j<<endl;
}