#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int q; cin >> q; while(q--) {
		int n;
		cin >> n;
		vector<int> a;
		map<int,int> b;
		for(int i = 0;i < n;i++) {
			int x;
			cin >> x;
			b[x]++;
		}
		int mx = 0;
		for(auto c : b) {
			a.push_back(c.second);
			mx = max(mx,c.second);
		}
		sort(a.begin(),a.end());
		int ans = 0, tmp = mx;
		int i = a.size() - 1;
		while(i >= 0 && tmp > 0) {
			//cout << tmp << " " << a[i] << endl;
			if(a[i] >= tmp) {
				ans+= tmp;
				tmp--;
			}
			else {
				ans += a[i];
				tmp = tmp = a[i] - 1;
			}
			
			i--;
		}
		cout << ans << endl;
	}
}