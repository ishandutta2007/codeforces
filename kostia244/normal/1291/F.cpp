#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
int n, k;
deque<int> cur;
void reset() {
	cout << "R" << endl;
	while(!cur.empty()) cur.pop_back();
}
bool add(int x) {
	cur.push_back(x);
	if(cur.size() > k) cur.pop_front();
	cout << "? " << x << endl;
	char c;
	cin >> c;
	return c == 'N';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	vector<vector<int>> lol;
	int Bs = k>1?k/2:1;
	for(int i = 1; i <= n; i++) {
		if(lol.empty() || lol.back().size() == Bs) lol.push_back({});
		lol.back().push_back(i);
	}
	int m = lol.size();
	for(int i = 0; i < m; i++) {
		for(int j = i+1; j < m; j++) {
			vector<int> ni, nj;
			for(auto x : lol[i]) if(add(x)) ni.push_back(x);
			for(auto x : lol[j]) if(add(x)) nj.push_back(x);
			lol[i] = ni, lol[j] = nj;
			reset();
		}
	}
	int ans = 0;
	for(auto i : lol) ans += i.size();
	cout << "! " << ans << endl;
	return 0;
}