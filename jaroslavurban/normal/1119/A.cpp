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

const int N=300010;
int a[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int n;cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	int l=0,r=n-1;
	while(a[l]==a[r])++l;
	int dist=r-l;
	l=0;
	while(a[l]==a[r])--r;
	cout<<max(dist,r-l)<<endl;
}