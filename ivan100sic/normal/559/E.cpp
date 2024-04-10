/*
	Stavljam sebe opet na zid srama - bacio sam pogled na
	editorial, komentare, pa cak i kodove pre pisanja ovoga.

	Ne razumem ovo resenje trenutno.
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
pair<int, int> a[105];
map<int, int> dp[105];

void mx(int& x, int y) {
	x = max(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a, a+n);
	dp[0][-1e9] = 0;
	for (int i=0; i<n; i++) {
		for (auto [r, val] : dp[i]) {
			int jbt = r; // wtf is this?
			for (int j=i; j<n; j++) {
				for (int tip=0; tip<2; tip++) {
					int v = a[j].first + a[j].second * tip;
					int u = v - a[j].second;
					jbt = max(jbt, v);
					// wtf does this even do
					mx(dp[j+1][jbt], val-max(r,u)+jbt);
				}
			}
		}
	}
	int sol = 0;
	for (auto [r, val] : dp[n])
		mx(sol, val);
	cout << sol << '\n';
}