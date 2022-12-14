#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n, d; cin >> n >> d;
		vector<int> a(n + 1);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		a[n] = d + 1;
		multiset<int> st;
		for(int i = 0; i < n; ++i){
			if(i) st.insert(a[i] - a[i - 1] - 1);
			else st.insert(a[i] - 1);
		}
		int ans = 0;
		for(int i = 0; i < n; ++i){
			int ld = (i ? a[i] - a[i - 1] - 1 : a[i] - 1);
			st.erase(st.find(ld));
			if(i + 1 < n) st.erase(st.find(a[i + 1] - a[i] - 1));
			st.insert(a[i + 1] - (i ? a[i - 1] + 1 : 1));
			ma(ans, min(*st.begin(), ((*(--st.end())) - 1) / 2));
			ma(ans, min(*st.begin(), d - a[(i == n - 1 ? n - 2 : n - 1)] - 1));
			st.erase(st.find(a[i + 1] - (i ? a[i - 1] + 1 : 1)));
			st.insert(ld);
			if(i + 1 < n) st.insert(a[i + 1] - a[i] - 1);
		}
		cout << ans << '\n';
	}
	return 0;
}