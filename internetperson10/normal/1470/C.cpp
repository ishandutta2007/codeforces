#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
vector<int> nums, nums2;
bool check[100001];

int ask(int n) {
	cout << "? " << n+1 << endl;
	int x;
	cin >> x;
	return x;
}

void answer(int n) {
	cout << "! " << n+1 << endl;
	return;
}

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	srand(time(NULL));
	int n, k;
	cin >> n >> k;
	nums.resize(n, k);
	nums2.resize(n, 0);
	for(int i = 0; i < n; i++) check[i] = true;
	int g = 0, y = k;
	for(int i = 0; i < 1000; i++) {
		if(y != k) g += 2;
		else if(g == 251*263) g += 255;
		else if(!(g%251)) g += 263;
		else g += 251; 
		g %= n;
		int x = ask(g);
		for(int j = 0; j < n; j++) {
			if(nums[j] != x) {
				// cout << "Not " << (g-j+n)%n;
				check[(g-j+n)%n] = false;
			}
		}
		nums2[0] = (nums[n-1]+1)/2 + nums[1]/2;
		nums2[n-1] = (nums[n-2]+1)/2;
		nums2[1] = nums[0] + nums[2]/2;
		for(int i = 2; i < n-1; i++) {
			nums2[i] = (nums[i-1]+1)/2 + nums[i+1]/2;
		}
		nums.swap(nums2);
		vector<int>().swap(nums2);
		nums2.resize(n, 0);
		if(x == n && y != n) g--;
		y = x;
	}
	for(int i = 0; i < n; i++) {
		if(check[i]) {
			answer(i);
			return 0;
		}
	}
}