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
		vector<int> a(n + 2);
		for(int i = 1; i <= n; i++) cin >> a[i];
		ll ans = 0;
		for(int i = 1; i <= n; i++){
			ans += abs(a[i] - a[i - 1]);
			if(a[i] > max(a[i - 1], a[i + 1])){
				ans -= a[i] - max(a[i - 1], a[i + 1]);
			}
		}
		ans += a[n];
		cout << ans << endl;
	}
}