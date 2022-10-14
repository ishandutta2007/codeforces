#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<18;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	for(auto &i : a) cin >> i[0] >> i[1];
	int ans = 1<<30;
	for(int h = 1; h <= 1000; h++) {
		int ok = 1;
		for(auto &i : a) if(min(i[0], i[1]) > h) ok = 0;
		if(!ok) continue;
		int extra = (n/2);
		int sumw = 0;
		vector<int> lol;
		for(auto &i : a) {
			if(i[1] > h) sumw += i[1], extra--;
			else {
				sumw += i[0];
				if(i[0] <= h)
					lol.push_back(i[0]-i[1]);
			}
		}
		if(extra < 0) continue;
		sort(all(lol));
		while(extra && lol.size() && lol.back() > 0) {
			sumw -= lol.back();
			lol.pop_back();
			extra--;
		}
		ans = min(ans, h*sumw);
	}
	cout << ans << '\n';
}