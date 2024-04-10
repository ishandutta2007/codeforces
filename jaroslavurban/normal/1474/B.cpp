#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// bool xd=any_of(a.begin(),a.end(),[&](int x){return x==9;});
// all_of, none_of
// int cnt=count(a.begin(),a.end(),x);
// bool found=binary_search(a.begin(),a.end(),x); true if x in sorted array
// int xd=*max_element(a.begin(),a.end());
// min_element

typedef long long ll;
typedef long double ld;

vector<ll>a;
vector<ll> erat (ll n){
    a = vector<ll>(n,0);
    vector<ll> primes;
    a[0] = a[1] = 1;
    for (ll i = 2; i < n; ++i){
        if (!a[i]){
            primes.push_back(i);
            for (ll j = i; j < n; j += i) a[j] = i;
        }
    }
    return primes;
}


main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	vector<ll>primes=erat(100000);
	while(tc--){
		int d;cin>>d;
		ll a=*lower_bound(primes.begin(),primes.end(),d+1);
		ll b=*lower_bound(primes.begin(),primes.end(),a+d);
		cout<<a*b<<endl;
	}
}