#include <bits/stdc++.h>

using namespace std;

int nums[100001], taken[100001];

int ask(string s, int i, int j) {
	i++; j++;
	cout << s << ' ' << i << ' ' << j << '\n';
	int x;
	cin >> x;
	return x;
}

int main() {
	int n, t = -1, g = -1;
	cin >> n;
	nums[0] = 0;
	taken[0]++;
	for(int i = 1; i < n; i++) {
		int k = ask("XOR", i-1, i);
		nums[i] = nums[i-1]^k;
		if(taken[nums[i]]) {
			t = nums[i];
		}
		taken[nums[i]]++;
	}
	if(t == -1) {
		for(int i = 0; i < n; i++) {
			if(nums[i] == 1) t = i;
		}
		int x = ask("AND", 0, t);
		for(int i = 0; i < n; i++) {
			if(nums[i] == 2) t = i;
		}
		int y = ask("AND", 0, t);
		if(y%2) x++;
		for(int i = 0; i < n; i++) nums[i] ^= x;
	}
	else {
		int j, k;
		j = k = -1;
		for(int i = 0; i < n; i++) {
			if(nums[i] == t) {
				k = i;
				swap(j, k);
			}
		}
		int x = ask("AND", j, k);
		x ^= t;
		for(int i = 0; i < n; i++) nums[i] ^= x;
	}
	cout << '!';
	for(int i = 0; i < n; i++) cout << ' ' << nums[i];
	cout << endl;
}