#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
const int mn = 1e5 + 10;
int lo[mn], net[mn];
string s;
vector<int> pos, neg;
int zero;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n,i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> s;
		int cur=0;
		for (char c : s) {
			if (c == '(')cur++;
			else cur--;
			lo[i] = min(lo[i], cur);
		}
		net[i] = cur;
	}
	for (i = 0; i < n; i++) {
		if (net[i] == 0 && lo[i] == 0)zero++;
		else if (lo[i] == 0)pos.push_back(net[i]);
		else if (lo[i] < 0 && lo[i] == net[i])neg.push_back(-net[i]);
	}
	int ans = zero / 2;
	int j=0;
	sort(pos.begin(),pos.end());
	sort(neg.begin(), neg.end());
	for (i = 0; i < pos.size(); i++) {
		while (j < neg.size() && neg[j] < pos[i])j++;
		if (j < neg.size() && neg[j] == pos[i])ans++, j++;
	}
	printf("%d", ans);
}