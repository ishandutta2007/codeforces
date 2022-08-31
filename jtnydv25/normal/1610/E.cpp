#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define T pii
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		for(int& x: a) cin >> x;
		int ans = n;
		for(int i = 0; i < n; i++){
			if(i != 0 && a[i] == a[i - 1]) continue;
			int k = 0, j = i;
			while(j < n && a[i] == a[j]){
				j++; k++;
			}
			while(j < n){
				// take j
				k++;
				int nw = a[j] + a[j] - a[i];
				// first >= nw
				j = lower_bound(all(a), nw) - a.begin();
			}
			ans = min(ans, n - k);
		}
		cout << ans << endl;
	}
}