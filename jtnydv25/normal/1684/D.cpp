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
		int n, k; cin >> n >> k;
		vector<int> a(n);
		vector<int> b(n);
		ll ans = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i]; ans += a[i];
			b[i] = a[i] + i;
		}
		sort(all(b));
		reverse(all(b));
		ll sum = ans;
		ll sum2 = 0;
		for(int r = 1; r <= k; r++){
			sum2 += b[r - 1];
			ans = min(ans, sum - sum2 + (n - 1) * (ll) r - (r * (ll) (r - 1)) / 2);
		}
		cout << ans << endl;
	}
}