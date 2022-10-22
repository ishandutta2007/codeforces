#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
int dist[101][101], arr[1010101];
string s;
bool edge[101][101];
vector<pii> ans;

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> s;
		for (int j=1; j<=n; j++) edge[i][j] = s[j-1]-'0';
	}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (edge[i][j]) dist[i][j] = 1;
			else dist[i][j] = 1e9;
		}
	}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			for (int k=1; k<=n; k++) {
				if (j==k) continue;
				dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]);
			}
		}
	}

	cin >> m;
	for (int i=0; i<m; i++) cin >> arr[i];

	for (int i=0; i<m; i++) {
		if (ans.empty()) {ans.push_back(pii(arr[i], i)); continue;}

		pii last = ans[ans.size()-1];
		if (dist[last.va][arr[i]] == i-last.vb) continue;
		ans.push_back(pii(arr[i-1], i-1));
	}
	ans.push_back(pii(arr[m-1], m-1));

	cout << ans.size() << '\n';
	for (int i=0; i<ans.size(); i++) cout << ans[i].va << ' ';
}