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
		int n; cin >> n;
		vector<int> a(n);
		vector<int> f(n, -1), g(n+1, n);
		for(int i = 0; i < n; i++) cin >> a[i];
		int cnt = 0;
		for(int i = 0; i < n - 1; i++){
			f[i] = i == 0 ? -1: f[i - 1];
			if(a[i] == a[i + 1] && f[i] == -1) f[i] = i;
			if(a[i] == a[i + 1]) cnt++;
		}
		for(int i = n - 2; i >= 0; i--){
			g[i] = (g[i + 1] == n && a[i] == a[i + 1]) ? i : g[i + 1];
		}

		if(cnt <= 1){
			cout << 0 << endl;
			continue;
		}
		int ans = n + 10;
		for(int i = 0; i < n - 1; i++){
			int u = i < 2 ? -1: f[i - 2];
			int v = g[i + 2];
			ans = min(ans, 1 + (u == -1 ? 0 : i - u - 1) + (v == n ? 0: v - i - 1));
		}
		cout << ans << endl;
	}
}