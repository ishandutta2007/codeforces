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
	while(t--) {
		int n;
		cin >> n;
		int sum = 0;
		for(int i = 0; i < n; i++) {
			int a;
			cin >> a;
			sum += a;
		}
		if((sum + n) % 2 == 1) {
			cout << "errorgorn\n";
		} else {
			cout << "maomao90\n";
		}
	}
}