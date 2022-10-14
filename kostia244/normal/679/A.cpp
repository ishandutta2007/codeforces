#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<20, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int c = 0;
	for(int i = 0; i < primes.size(); i++) {
		cout << primes[i] << endl;
		string s; cin >> s;
		c += s == "yes";
		if(s == "yes" && primes[i]*primes[i] <= 100) {
			cout << primes[i]*primes[i] << endl;
			cin >> s;
			if(s == "yes") return cout << "composite" << endl, 0;
		}
	}
	cout << (c<2?"prime":"composite") << endl;
}