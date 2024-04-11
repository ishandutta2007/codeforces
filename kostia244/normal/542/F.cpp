#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1010;
int n, T;
vector<int> f[maxn];
array<int, maxn> dp, def;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> T;
	for(int x, y, i = 1; i <= n; i++) {
		cin >> x >> y;
		f[T-x].push_back(y);
	}
	for(int i = 0; i < T; i++) {
		sort(begin(f[i]), end(f[i]));
		f[i].push_back(0);
		reverse(begin(f[i]), end(f[i]));
		for(int j = 1; j < f[i].size(); j++) f[i][j] += f[i][j-1];
		//cout << i << " : ";for(int j = 0; j < f[i].size(); j++) cout << f[i][j] << " "; cout << '\n';
	}
	fill(begin(def), end(def), -(1<<30));
	dp = def;
	dp[1] = 0;
	int ans = 0;
	for(int i = 0; i < T; i++) {
		for(int i = n-1; i>=0; i--) dp[i] = max(dp[i], dp[i+1]);
		array<int, maxn> ndp = def;
		for(int it = 0; it <= n; it++) {
			for(int j = 0; j < f[i].size() && it+j <= n; j++) {
				ndp[it] = max(ndp[it], dp[it+j] + f[i][j]);
			}
		}
		//cout << i << ":\n";
		//for(int i = 0; i <= n; i++) cout << ndp[i] << " "; cout << '\n';
		ans = max(ans, *max_element(begin(ndp), end(ndp)));
		dp = ndp;
		ndp = def;
		multiset<int> st;
		for(int i = 0; i <= n; i++) {
			st.insert(dp[i]);
			ndp[i] = *st.rbegin();
			if(i%2 == 0) st.erase(st.find(dp[i/2]));
		}
		//for(int i = 0; i <= n; i++) cout << ndp[i] << " "; cout << '\n';
		dp = ndp;
	}
	cout << ans << '\n';
}