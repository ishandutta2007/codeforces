#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;
string s;
vector<int> pre[202020];
vector<int> dp;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	for (int i=1; i<=202020; i++) {
		int k=0;
		while ((1<<k) <= i) ++k;
		pre[i-k].push_back(i);
	}

	cin >> t;
	while (t--) {
		cin >> s;
		dp.resize(0);
		dp.resize(s.size());

		if (s[s.size()-1] == '0') dp[s.size()-1] = 1;
		for (int i=s.size()-2; i>=0; i--) {
			if (s[i] == '1') dp[i] = 0;
			else dp[i] = dp[i+1]+1;
		}

		int cnt = 0;
		for (int i=0; i<s.size(); i++) {
			for (int x : pre[dp[i]]) {
				int num = 0;
				int idx = i+dp[i];

				while (idx<s.size() && num<x) {
					num*=2;
					num += (s[idx]-'0');
					++idx;
				}

				if (num==x) {
					++cnt;
				}
			}
		}

		cout << cnt << '\n';
	}
}