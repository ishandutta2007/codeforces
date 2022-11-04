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
	int n,m;cin>>n>>m;
	int e1=0,e2=0,o1=0,o2=0;
	for(int i=0;i<n;++i){
		int a;cin>>a;
		if(a%2)++o1;
		else ++e1;
	}
	for(int i=0;i<m;++i){
		int a;cin>>a;
		if(a%2)++o2;
		else ++e2;
	}
	cout<<min(e1,o2)+min(o1,e2)<<endl;
}