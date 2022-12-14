#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Fenwick{
	int n;
	vector<int> tree;
	Fenwick(int N):n(N){
		tree.resize(n);
	}
	void push(int x, int y){
		for(int i = x; i < n; i |= i + 1) tree[i] += y;
	}
	int get(int x){
		int rv = 0;
		for(int i = x; i >= 0; i = (i & (i + 1)) - 1){
			rv += tree[i];
		}
		return rv;
	}
};

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int n = (int)s.size();
		vector<vector<int>> pos(4);
		vector<int> cnt(4);
		for(int i = 0; i < n; ++i){
			if(s[i] == 'A') pos[0].push_back(i);
			if(s[i] == 'N') pos[1].push_back(i);
			if(s[i] == 'T') pos[2].push_back(i);
			if(s[i] == 'O') pos[3].push_back(i);
		}
		vector<int> ord = {0, 1, 2, 3};
		int ans = -1;
		vector<int> out;
		do{
			vector<int> a(n);
			int acnt = 0;
			for(auto&i:ord){
				for(auto&j:pos[i]){
					a[acnt++] = j;
				}
			}
			Fenwick tree(n + 4);
			for(int i = 1; i <= n; ++i){
				tree.push(i, 1);
			}
			int sum = 0;
			for(auto&i:a){
				sum += tree.get(i);
				tree.push(i + 1, -1);
			}
			if(sum > ans){
				ans = sum;
				out = ord;
			}
		}while(next_permutation(ord.begin(), ord.end()));
		for(auto&i:out){
			for(int j = 0; j < (int)pos[i].size(); ++j){
				if(i == 0) cout << 'A';
				if(i == 1) cout << 'N';
				if(i == 2) cout << 'T';
				if(i == 3) cout << 'O';
			}
		}
		cout << '\n';
	}
	return 0;
}