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

const int N=200010;
int a[N];
int n,z;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>z;
	for(int i=0;i<n;++i)cin>>a[i];
	sort(a,a+n);
	int last=n-1;
	for(int i=(n+1)/2;i>=0;--i)
		if(a[last]-a[i]>=z)--last;
	cout<<min(n/2,n-1-last)<<endl;
}