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
#endif
const int mod = 1e9 + 7;
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		int v = (1 << 30) - 1;
		for(int & x : a){
			cin >> x;
			v &= x;
		}
		int cnt = 0;
		for(int x : a) if(x == v) cnt++;
		int ans = (cnt * 1LL * (cnt - 1)) % mod;
		for(int i = 1; i <= n - 2; i++) ans = (ans * 1LL * i) % mod;
		cout << ans << endl;
	}
}