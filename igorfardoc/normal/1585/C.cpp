#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, k;

ll solve_for(vi a) {
	ll ans = 0;
	if(a.empty()) {
		return ans;
	}
	ans += a[a.size() - 1];
	for(int i = (int)a.size() - k - 1; i >= 0; i-=k) {
		ans += 2 * a[i];
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--) {
    	cin >> n >> k;
    	vi a, b;
    	for(int i = 0; i < n; i++) {
    		int c;
    		cin >> c;
    		if(c > 0) {
    			a.push_back(c);
    		} else if(c < 0) {
    			b.push_back(-c);
    		}
    	}
    	sort(a.begin(), a.end());
    	sort(b.begin(), b.end());
    	ll ans = solve_for(a) + solve_for(b);
    	if(!a.empty() && !b.empty()) {
    		ans += min(a[a.size() - 1], b[b.size() - 1]);
    	}
    	cout << ans << '\n';
	}
}