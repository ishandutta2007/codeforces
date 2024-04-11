#include<bits/stdc++.h>
#define time orz
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<20;
int n, m;
vector<array<int, 4>> edges;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	string s;
	while(t--) {
		int n;cin >> n;
		vector<int> f(n);
		for(auto &i : f) cin >> i;
		sort(all(f), greater<>());
		for(auto i : f) cout << i << " "; cout << '\n';
	}

}