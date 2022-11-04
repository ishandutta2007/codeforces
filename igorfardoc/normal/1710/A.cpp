#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;

bool check(vi a, int need) {
	bool all2 = true;
	for(const auto& el : a) {
		if(el != 2) all2 = false;
	}
	ll sum = 0;
	for(const auto& el : a) {
		sum += el;
	}
	if(all2) {
		if(sum >= need && need % 2 == 0) return true;
		return false;
	} else {
		return sum >= need;
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
		int n, m, k;
		cin >> n >> m >> k;
		if(n > m) swap(n, m);
		int sum1 = n;
		int sum2 = m;
		vi all1, all2;
		for(int i = 0; i < k; i++) {
			int a;
			cin >> a;
			int can1 = a / m;
			if(can1 > 1) {
				all1.push_back(can1);
			}
			int can2 = a / n;
			if(can2 > 1) {
				all2.push_back(can2);
			}
		}
		if(check(all1, sum1) || check(all2, sum2)) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}

	}
}