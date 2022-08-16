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
	int n; cin >> n;
	vector<int> c(n + 1);
	vector<ll> pref(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> c[i];
		pref[i] = pref[i - 1] + (i % 2 == 0 ? -c[i] : c[i]);
	}
	ll ans = 0;
	// trace(pref);
	for(int i = 1; i <= n; i +=2){
		ll minp = 0;
		ll sum = 0;
		for(int j = i + 1; j  <= n; j += 2){
			ll L2 = pref[j], R2 = pref[j - 1] - 1;
			ll L1 = pref[i - 1], R1 = pref[i] + minp;
			if(L1 <= R1){
				ans += max(0LL, min(R1, R2) - max(L1, L2) + 1);
			}
			// trace(i, j, ans, minp, sum);
			// trace(L1, R1, L2, R2);
			sum -= c[j];
			minp = min(minp, sum);
			if(j < n) sum += c[j + 1];
		}
	}
	cout << ans << endl;
}