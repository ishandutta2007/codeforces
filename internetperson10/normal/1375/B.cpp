#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<int> > nums;

int main() {
	ios::sync_with_stdio(false);
	bool sad;
	ll t, n, m, x;
	string s;
	char c;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		sad = false;
		for(int i = 0; i < n; i++) {
			nums.push_back(vector<int>());
			for(int j = 0; j < m; j++) {
				x = ((i == 0) || (i == n-1)) + ((j == 0) || (j == m-1));
				if(x == 2) nums[i].push_back(2);
				else if(x == 1) nums[i].push_back(3);
				else nums[i].push_back(4);
			}	
			for(int j = 0; j < m; j++) {
				cin >> x;
				if(x > nums[i][j]) sad = true;
			}	
		}
		if(sad) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cout << nums[i][j] << ' ';
			}
			cout << '\n';
			}

		}
		vector<vector<int>>().swap(nums);
	}
}