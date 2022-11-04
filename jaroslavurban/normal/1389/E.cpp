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


ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		ll m,d,w;cin>>m>>d>>w;
		m=min(m,d);
		w/=gcd(d-1,w);
		ll bg=m/w;
		ll cntb=m%w;
		ll res=cntb*(bg+1)*bg/2+(w-cntb)*bg*(bg-1)/2;
		cout<<res<<endl;
	}
}