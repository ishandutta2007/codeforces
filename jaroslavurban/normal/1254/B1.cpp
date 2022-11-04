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
vector<ll> aa; // a[i]=highest prime factor of i
vector<ll> erat (ll n){
    aa = vector<ll>(n,0);
    vector<ll> primes;
    aa[0] = aa[1] = 1;
    for (ll i = 2; i < n; ++i){
        if (!aa[i]){
            primes.push_back(i);
            for (ll j = i; j < n; j += i) aa[j] = i;
        }
    }
    return primes;
}
const int N=100100,inf=1e18;
int n,cnt1,res=inf;
int a[N];
int tr(int p){
	vector<vector<int>>idxs(cnt1/p,vector<int>(p));
	int c=0,res=0;
	for(int i=0;i<n;++i)
		if(a[i]){
			idxs[c/p][c%p]=i;
			++c;
		}
	for(int i=0;i<cnt1/p;++i){
		int med=idxs[i][p/2];
		for(int j=0;j<p;++j)res+=abs(med-idxs[i][j]);
	}
	return res;
}
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i)if(a[i])++cnt1;
	auto primes=erat(N);
	for(int i=0;i<primes.size();++i)
		if(cnt1%primes[i]==0)
			res=min(res,tr(primes[i]));
	if(res==inf)cout<<-1<<endl;
	else cout<<res<<endl;
}