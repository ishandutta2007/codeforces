#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<18, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	int n;
	while(t--) {
		cin >> n;
		int lst = -1;
		vector<array<int, 2>> a;
		vector<int> freq(n+1);
		int N = 0;
		freq[0] = 2, N+=2;//make it a circle
		for(int t, i = 0; i < n; i++) {
			cin >> t;
			if(i == 0) freq[t]++, N++;
			if(i == n-1) freq[t]++, N++;
			if(i) {
				if(lst == t) {
					freq[t] += 2;
					N+=2;
				} else a.push_back({lst, t});
			}
			lst = t;
		}
		int f = max_element(all(freq))-freq.begin(), s = 0;
		for(auto &i : freq) {
			s += i;
		}
		int req = 2*freq[f] - s;
		//cout << s << " " << freq[f] << " " << req << " " << N << endl;
		for(auto &[x, y] : a) {
			if(x != f && y != f && req > 0) N+=2, req-=2;
		}
		
		if(req > 0) cout << "-1\n";
		else cout << (N/2) - 2 << '\n';
	}
}