#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<int> nums = {32, 256, 8192};
vector<pair<int, int>> ops;
vector<int> curr;

void add(int x, int y) {
	ops.push_back({x, y});
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if(n <= 32) {
			for(int i = 3; i < n; i++) {
				add(i, n);
			}
			int k = n;
			while(k != 1) {
				add(n, 2);
				k = (k+1)/2;
			}
		}
		else {
			int x, y;
			if(n <= 256) {
				x = 8; y = 32;
			}
			else if(n <= 8192) {
				x = 32; y = 256;
			}
			else {
				x = 256; y = 8192;
			}
			for(int i = 2; i < n; i++) {
				if(i != x && i != y) add(i, n);
			}
			add(n, y);
			add(n, y);
			int x1 = x, y1 = y;
			while(x1 + y1 > 3) {
				if(x1 < y1) {
					add(y, x);
					y1 /= x1;
				}
				else {
					add(x, y);
					x1 /= y1;
				}
			}
		}
		curr.resize(n);
		for(int i = 0; i < n; i++) curr[i] = i+1;
		cout << ops.size() << '\n';
		for(int i = 0; i < ops.size(); i++) {
			cout << ops[i].first << ' ' << ops[i].second << '\n';
			int x = ops[i].first, y = ops[i].second;
			x--; y--;
			if(curr[x]%curr[y]) {
				curr[x] /= curr[y]; curr[x]++;
			}
			else curr[x] /= curr[y];
		}
		int sum = 0;
		for(int i = 0; i < curr.size(); i++) {
			sum += curr[i];
		}
		if(sum != n+1) cerr << "BAAAAAAAAAAAAAD\n";
		vector<int>().swap(curr);
		vector<pair<int, int>>().swap(ops);
	}
}