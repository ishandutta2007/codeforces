#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<ll, ll>
#define mod 1000000007ll
using namespace std;

int n, w, h, tw, th, dp[5004], p[5004];
__V<pair<pi, ll>> c;

void bt(int i) {
	if (p[i] != -1)
		bt(p[i]);
	cout << c[i].second << " ";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> w >> h;
	c.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> tw >> th;
		if (tw > w && th > h)
			c[i] = pair<pi, ll>(pi(tw, th), i+1);
			else c[i] = pair<pi, ll>(pi(0, 0), -1);
		}
	sort(c.begin(), c.end());
	for (int i = 0; i <= n; i++)
		dp[i] = 1, p[i] = -1;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			if (c[i].second != -1 && c[j].second != -1
					&& c[j].first.first < c[i].first.first
					&& c[j].first.second < c[i].first.second
					&& (dp[j] + 1) > dp[i])
				dp[i] = dp[j] + 1, p[i] = j;
	int i = 0;
	for(int j = 0; j < n; j++)
		if(c[j].second != -1 && dp[j] >= dp[i]) i = j;
	if (c[i].second == -1)
		cout << "0";
	else {
		cout << dp[i] << "\n";
		bt(i);
	}
}