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
const int N = 10001;
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n), b(n);
		ll sum2 = 0;
		int sum = 0;
		int r = 0;
		for(int& x: a){
			cin >> x;
			sum += x;
			sum2 += x * x;
		}
		for(int& x: b){
			cin >> x;
			sum += x;
			sum2 += x * x;
		}
		bitset<N> bs;
		bs.set(0);
		for(int i = 0; i < n; i++){
			r += min(a[i], b[i]);
			bs |= bs << (max(a[i], b[i]) - min(a[i], b[i]));
		}
		int mn = 1<<30;
		for(int i = 0; i <= sum; i++) if(bs[i]){
			int j = r + i;
			// trace(j, ans);
			mn = min(mn, j * j + (sum - j) * (sum - j));
		}
		cout << sum2 * (n - 2) + mn << endl;
	}
}