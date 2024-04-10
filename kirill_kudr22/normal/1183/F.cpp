#include <bits/stdc++.h>
using namespace std;
#define int long long
int get_ans(vector<int> a) {
	int n = a.size();
	int ans = a[n - 1];
	int tmp = -1;
	for(int i = n - 2;i >= 0;i--) {
		if(tmp == -1) {
			if(a[n - 1] % a[i] != 0) {
				ans += a[i];
				tmp = a[i];
			}
		}
		else if(a[n - 1] % a[i] != 0 && tmp % a[i] != 0) {
			ans += a[i];
			break;
		}
	} 
	return ans;
}
signed main() {
	int q; cin >> q; while(q--) {
		int n;
		cin >> n;
		set<int> b;
		for(int i = 0;i < n;i++) {
			int x;
			cin >> x;
			b.insert(x);
		}
		vector<int> a;
		for(auto c : b) {
			a.push_back(c);
		}
		sort(a.begin(),a.end());
		int ans = get_ans(a);
		int x = a[a.size() - 1];
		while(a.size() > 0) {
			if(a[a.size() - 1] == x / 2 && x % 2 == 0) {
				ans = max(ans, get_ans(a));
			}
			a.pop_back();
		}
		cout << ans << endl;
	}
}