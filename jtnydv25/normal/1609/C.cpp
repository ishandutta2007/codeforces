#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif
const int N = 1000006;
bool prime[N];
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	fill(prime + 2, prime + N, true);
	
	for(int i = 2; i < N; i++) if(prime[i]){
		for(int j = 2 * i; j < N; j += i) prime[j] = false;
	}

	while(t--){
		int n, e;
		cin >> n >> e;
		vector<int> a(n);
		vector<int> firstPrime(2 * n + 1), firstNonPrime(2 * n + 1), firstNonOne(2 * n + 1);
		iota(all(firstPrime), 0);
		iota(all(firstNonPrime), 0);
		iota(all(firstNonOne), 0);
		for(int& x: a) cin >> x;
		ll ans = 0;
		for(int i = n - 1; i >= 0; i--){
			firstPrime[i] = prime[a[i]] ? i : firstPrime[i + e];
			firstNonPrime[i] = (a[i] != 1 && !prime[a[i]]) ? i : firstNonPrime[i + e];
			firstNonOne[i] = a[i] != 1 ? i : firstNonOne[i + e];
			int u = firstPrime[i], v = firstNonPrime[i];
			if(u < v){
				v = min(v, firstNonOne[u + e]);
				ans += (v - u) / e;
				if(u == i) ans--;
			}
			// trace(i, u, v, ans);
			// trace(ans);
		}
		cout << ans << endl;
		// return 0;
	}
}