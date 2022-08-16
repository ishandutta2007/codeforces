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
	int t; cin >> t;
	while(t--){
		int n, x; cin >> n >> x;
		vector<int> a(n);
		for(int& i: a) cin >> i;
		const ll INF = 1LL << 50;
		ll L = -INF, R = INF;
		int cnt = 0;
		for(int i = 0; i < n; i++){
			ll _L = max(L, (ll)a[i] - x);
			ll _R = min(R, (ll)a[i] + x);
			if(_L <= _R) {
				L = _L; R = _R; continue;
			} else{
				cnt++;
				L = a[i] - x, R = a[i] + x;
			}
		}
		cout << cnt << endl;
	}
}