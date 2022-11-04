#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;

vi go(vi a, int pref, int am) {
	auto b = a;
	for(int i = 0; i < pref; i++) {
		b[i] = a[(i - am + pref + pref) % pref];
	}
	return b;
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
		int n;
		cin >> n;
		vi ans(n);
		vi a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			--a[i];
		}
		for(int i = n - 1; i >= 0; i--) {
			int pos;
			for(int j = 0; j <= i; j++) {
				if(a[j] == i) pos = j;
			}
			ans[i] = ((pos + 1) % (i + 1));
			a = go(a, i + 1, -pos - 1);
		}
		for(const auto& el : ans) {
			cout << el << ' ';
		}
		cout << '\n';
	}
}