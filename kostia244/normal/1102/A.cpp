#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define FOR(_i, _n) for(_i = 0; _i < n; _i++)
#define FOR1(_i, _n) for(_i = 1; _i <= n; _i++)

int n;
vector<int> a;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	if(n&1) {
		n -= 3;
		n >>= 1;
		cout << (n&1);
	} else {
		n >>= 1;
		cout << (n&1);
	}
}