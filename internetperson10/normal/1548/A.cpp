#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<int> bigs;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, x, y, c, ans = 0;
	cin >> n >> m;
	bigs.resize(n+1);
	for(int i = 0; i < m; i++) {
		cin >> x >> y;
		if(x < y) swap(x, y);
		bigs[y]++; 
	}
	for(int i = 1; i <= n; i++) {
		if(bigs[i] == 0) ans++;
	}
	int q;
	cin >> q;
	while(q--) {
		cin >> c;
		if(c == 3) cout << ans << '\n';
		else {
			cin >> x >> y;
			if(x < y) swap(x, y);
			if(c == 1) {
				if(bigs[y] == 0) ans--;
				bigs[y]++;
			}
			if(c == 2) {
				bigs[y]--;
				if(bigs[y] == 0) ans++;
			}
		}
	}
}