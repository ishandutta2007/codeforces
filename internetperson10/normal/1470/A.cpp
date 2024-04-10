#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<ll> nums1, nums2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		nums1.resize(n);
		nums2.resize(m);
		for(int i = 0; i < n; i++) {
			cin >> nums1[i];
		}
		for(int i = 0; i < m; i++) {
			cin >> nums2[i];
		}
		sort(nums1.rbegin(), nums1.rend());
		ll ans = 0;
		int g = 1;
		for(int i = 0; i < n; i++) {
			if(g < nums1[i]) {
				ans += nums2[g-1];
				g++;
			}
			else ans += nums2[nums1[i]-1];
		}
		cout << ans << '\n';
		vector<ll>().swap(nums1);
		vector<ll>().swap(nums2);	
	}
}