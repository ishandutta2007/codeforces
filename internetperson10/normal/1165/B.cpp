#include<bits/stdc++.h>

using namespace std;

vector<int> nums;

int main() {
	int n, ans=0, curr=1;
	cin >> n;
	for(int a=0; a<n; a++) {
		int c;
		cin >> c;
		nums.emplace_back(c);
	}
	sort(nums.begin(), nums.end());
	for(int a=0; a<n; a++) {
		if(nums[a]<curr) continue;
		ans++;
		curr++;
	}
	cout << ans << '\n';
}