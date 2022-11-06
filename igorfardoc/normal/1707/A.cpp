#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
int n, q;
vi a;
vector<bool> here;

bool check(int sz) {
	here.assign(n, false);
	int now = q;
	for(int i = 0; i < n - sz; i++) {
		if(a[i] <= now) {
			here[i] = true;
		}
	}
	for(int i = n - sz; i < n; i++) {
		here[i] = true;
		if(now <= 0) return false;
		if(a[i] > now) now--;
	}
	return true;
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
		cin >> n >> q;
		a.resize(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		int l = 0;
		int r = n + 1;
		while(r - l > 1) {
			int mid = (l + r) / 2;
			if(check(mid)) {
				l = mid;
			} else {
				r = mid;
			}
		}
		check(l);
		for(int i = 0; i < n; i++) {
			if(here[i]) {
				cout << 1;
			} else {
				cout << 0;
			}
		}
		cout << '\n';
	}
}