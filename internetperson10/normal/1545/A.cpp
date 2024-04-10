#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<int> nums, nums2, nums3[4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		nums.resize(n);
		nums2.resize(n);
		for(int i = 0; i < n; i++) {
			cin >> nums[i];
			nums2[i] = nums[i];
		}
		sort(nums2.begin(), nums2.end());
		for(int i = 0; i < n; i++) {
			int g = 0;
			if(i%2) g = 2;
			nums3[g].push_back(nums[i]);
			nums3[g+1].push_back(nums2[i]);
		}
		sort(nums3[0].begin(), nums3[0].end());
		sort(nums3[2].begin(), nums3[2].end());
		bool sad = false;
		for(int z = 0; z < 2; z++) {
			for(int i = 0; i < nums3[z*2].size(); i++) {
				if(nums3[z*2][i] != nums3[z*2+1][i]) sad = true;
			}
		}
		cout << (sad ? "NO\n" : "YES\n");
		vector<int>().swap(nums);
		vector<int>().swap(nums2);
		for(int z = 0; z < 4; z++) vector<int>().swap(nums3[z]);
	}
}