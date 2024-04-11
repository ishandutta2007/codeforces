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
		cin >> s >> s;
		int cur = 0, mn = 0;
		for(auto &i : s) {
			if(i == '(') cur++;
			else cur--;
			mn = min(mn, cur);
		}
		cout << -mn << endl;
	}

}