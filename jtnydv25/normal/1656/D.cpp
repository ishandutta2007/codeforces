#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n' // remove in interactive
#endif

vector<int> primes;
const int N = 100000;

ll get(ll n){
	ll nn = n;
	ll p2 = 1;
	while(n % 2 == 0){
		n /= 2;
		p2 *= 2;
	}

	if(2 * p2 + 1 <= n){
		return 2 * p2;
	}

	//now n is small
	for(int p: primes){
		if(p * (ll) p > n) break;
		if(p * (ll) (p + 1) > 2 * nn){
			return -1;
		}
		if(n % p == 0){
			return p;
		}
	}
	// n is a prime
	if(n != 1 && n + 1 <= (2 * nn) / n){
		return n;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	vector<bool> P(N, true);
	for(int i = 2; i < N; i++) if(P[i]){
		if(i > 2) primes.push_back(i);
		for(int j = i; j < N; j += i) P[j] = false;
	}
	while(t--){
		ll n; cin >> n;
		cout << get(n) << endl;
	}
}