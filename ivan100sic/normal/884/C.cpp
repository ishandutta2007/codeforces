#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int p[100005];
bool vis[100005];

vector<int> a;

ll kv(ll x) {
	return x*x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> p[i];
	}

	for (int i=1; i<=n; i++) {
		if (!vis[i]) {
			int x = i, c=0;
			do {
				vis[x] = true;
				x = p[x];
				c++;
			} while (x != i);
			a.push_back(c);
		}
	}

	if (a.size() == 1) {
		cout << kv(n);
	} else {
		sort(a.begin(), a.end());
		ll sol = kv(a[a.size()-1] + a[a.size()-2]);
		for (size_t i=0; i<a.size()-2; i++) {
			sol += kv(a[i]);
		}
		cout << sol;
	}


}