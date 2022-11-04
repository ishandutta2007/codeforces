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

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int a,b,c;cin>>a>>b>>c;
	int x,y,z;cin>>x>>y>>z;
	if(a>=x)a=(a-x)/2;
	else a=a-x;
	if(b>=y)b=(b-y)/2;
	else b=b-y;
	if(c>=z)c=(c-z)/2;
	else c=c-z;
	if(a+b+c>=0)cout<<"Yes\n";
	else cout<<"No\n";
}