#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
vi a(200000, -1);
set<int> busy;
int n, q;
int now = 0;
ll sum = 0;

void replace(int i, int x) {
	if(a[i] == -1) {
		sum -= now;
	} else {
		sum -= a[i];
	}
	a[i] = x;
	busy.insert(i);
	sum += x;
}

void replace(int x) {
	for(const auto& el : busy) {
		a[el] = -1;
	}
	busy.clear();
	now = x;
	sum = (ll)x * n;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		int a; 
		cin >> a;
		replace(i, a);
	}
	for(int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if(t == 1) {
			int j, x;
			cin >> j >> x;
			--j;
			replace(j, x);
		} else {
			int x;
			cin >> x;
			replace(x);
		}
		cout << sum << '\n';
	}
}