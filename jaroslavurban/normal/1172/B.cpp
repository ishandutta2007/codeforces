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

const ll mod=998244353,N=200010;
ll cnt[N];
ll F[N];
int n;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	F[0]=1;
	for(int i=1;i<=n;++i)F[i]=F[i-1]*i%mod;
	for(int i=0;i<2*(n-1);++i){int u;cin>>u;++cnt[--u];}
	ll res=n;
	for(int i=0;i<n;++i)res=res*F[cnt[i]]%mod;
	cout<<res<<endl;
}