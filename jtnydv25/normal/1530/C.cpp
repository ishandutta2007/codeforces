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
#define endl '\n'
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n), b(n);
		for(int & x : a) cin >> x;
		for(int & x : b) cin >> x;
		vector<ll> pa(n + 1), pb(n + 1);
		sort(all(a));
		sort(all(b));
		reverse(all(b));
		for(int i = 0; i < n; i++){
			pa[i + 1] = pa[i] + a[i];
			pb[i + 1] = pb[i] + b[i];
		}
		int lo = 0, hi = 4 * n;
		while(lo < hi){
			int k = (lo + hi) >> 1;
			int pos = min((n + k) / 4, n);
			// trace(pos)
			ll sa = pa[n] + 100 * k - pa[pos];
			if((n + k) / 4 > n) sa -= 100 * ((n + k) / 4 - n);
			pos = min(n, n + k - (n + k) / 4);
			ll sb = pb[pos];
			// trace(k, sa, sb);
			if(sa >= sb) hi = k;
			else lo = k + 1;
		}
		cout << lo << endl;
	}
}