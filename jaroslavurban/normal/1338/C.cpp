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

int p[4][3][2]={{{0,0},{0,0},{0,0}},
								{{1,0},{0,1},{1,1}},
								{{0,1},{1,1},{1,0}},
								{{1,1},{1,0},{0,1}}};
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		ll n;cin>>n;
		if(n<=3){cout<<n<<endl;continue;}
		n-=4;
		ll nn=n/3;
		ll d=4;
		vector<int>res;
		while(nn>=d){
			nn-=d;
			d*=4;
		}
		for(ll i=4;i<=d;i*=4){
			res.push_back(p[nn%4][n%3][0]);
			res.push_back(p[nn%4][n%3][1]);
			nn/=4;
		}
		res.push_back(p[1][n%3][0]);
		res.push_back(p[1][n%3][1]);
		ll r=0;
		for(ll i=0;i<res.size();++i)if(res[i])r|=(1ll<<i);
		cout<<r<<endl;
	}
}