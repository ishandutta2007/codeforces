#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

const int N=1010;
int a[N];
int n,h;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>h;
	int res=0;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i){
		int hh=0;
		sort(a,a+i+1);
		for(int j=i;j>=0;j-=2)hh+=a[j];
		if(hh<=h)res=i;
	}
	cout<<res+1<<endl;
}