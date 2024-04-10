#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	vl mass = {0};
	for(int i = 1; i <= 1000000; i++) {
		int a = i / 3;
		int b = (i - a) / 2;
		int c = i - a - b;
		ll res = (ll)a * (b + c) + (ll)b * (c + a) + (ll)c * (a + b);
		mass.push_back(res);
	}
	while(t--) {
		int n;
		cin >> n;
		int id = lower_bound(mass.begin(), mass.end(), n) - mass.begin();
		cout << id << '\n';
	}
}