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



int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		vector<int> a(n);
		ll s = 0;
		for(int& x: a){
			cin >> x;
			s += x;
		}
		int u = min_element(all(a)) - a.begin();
		int v = max_element(all(a)) - a.begin();
		ll mn = a[u] * (ll) (n - 2) + s;
		ll mx = a[v] * (ll) (n - 2) + s;
		if(mn > 0 || mx < 0){
			cout << "INF" << endl;
			continue;
		}
		vector<int> b(n);
		function<__int128_t(int)> MST = [&](int t){
			for(int i = 0; i < n; i++) b[i] = a[i] + t;
			int p = min_element(all(b)) - b.begin(), q = max_element(all(b)) - b.begin();
			int tmp;
			if(p == q){
				q = (p + 1) % n;
			}
			__int128_t ret = b[p] * (ll) b[q] - t * __int128_t(t) * __int128_t(n - 1);
			for(int i = 0; i < n; i++) if(i != p && i != q){
				if(b[i] < 0) ret += b[q] * (ll) b[i];
				else ret += b[p] * (ll) b[i];
			}
			return ret;
		};
		ll O = 1000000000;
		ll lo = 0, hi = 2 * O;
		while(lo < hi){
			// trace(lo, hi);
			int t = (lo + hi) / 2;
			if(MST(t - O) < MST(t + 1 - O)){
				lo = t + 1;
			} else hi = t;
		}
		cout << (ll)MST(lo - O) << endl;
	}
}