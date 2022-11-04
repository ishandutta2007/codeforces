#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
int n, m;
vvi a;
int c, d;

void check(int fir, int sec) {
	if(c != -1) return;
	auto b = a;
	for(int i = 0; i < n; i++) {
		if(fir == sec) continue;
		swap(b[i][fir], b[i][sec]);
	}
	bool ok = true;
	for(int i = 0; i < n; i++) {
		for(int j = 1; j < m; j++) {
			if(b[i][j] < b[i][j - 1]) ok = false;
		}
	}
	if(ok) {
		c = fir;
		d = sec;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		a.assign(n, vi(m));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		c = d = -1;
		check(0, 0);
		for(int i = 0; i < n; i++) {
			vi here;
			auto b = a[i];
			sort(b.begin(), b.end());
			for(int j = 0; j < m; j++) {
				if(a[i][j] != b[j]) {
					here.push_back(j);
				}
			}
			if(here.size() == 2) {
				check(here[0], here[1]);
				break;
			}
		}
		if(c == -1) {
			cout << -1 << '\n';
			continue;
		}
		cout << c + 1 << ' ' << d + 1 << '\n';
	}

}