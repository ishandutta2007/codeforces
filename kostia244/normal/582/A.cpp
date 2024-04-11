#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5050, mod = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	n = n*n;
	vector<int> f(n);
	for(auto &i : f) cin >> i;
	multiset<int, greater<int>> u;
	for(auto i : f) u.insert(i);
	vector<int> ans;
	ans.push_back(*u.begin()), u.erase(u.begin());
	while(u.size()) {
		int v = *u.begin(); u.erase(u.begin());
		for(auto &i : ans) u.erase(u.find(__gcd(v, i))), u.erase(u.find(__gcd(v, i)));
		ans.push_back(v);
	}
	for(auto i : ans) cout << i << " ";cout << endl;
}