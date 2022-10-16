#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n' // remove in interactive
#endif

ll get_ceil(ll a, ll b){
	if(a >= 1) return (a - 1) / b + 1;
	return -(abs(a) / b);
}

void solve(){
	int n, k; cin >> n >> k;
		vector<ll> s(n + 1);
		for(int i = n - k + 1; i <= n; i++) cin >> s[i];

		vector<ll> a(n + 1);
		for(int i = n; i >= n - k + 2; i--){
			a[i] = s[i] - s[i - 1];
			if(i != n && a[i] > a[i + 1]){
				cout << "No" << endl;
				return;
			}
		}
		ll mn = get_ceil(s[n - k + 1], n - k + 1);
		if(k != 1 && mn > a[n - k + 2]){
			cout << "No" << endl;
			return;
		}
		cout <<  "Yes" << endl;
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		solve();
	}
}