#include <bits/stdc++.h>

using namespace std;
const int N = 100100;
long long n, k, m, a, ans;
vector <int> v[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= 2 * n; i++) {
		cin >> a;
		v[a].push_back(i);
	}

	v[0].push_back(1);
	v[0].push_back(1);
	for(int i = 1; i <= n; i++) {
		ans += abs(v[i][0] - v[i - 1][0]);
		ans += abs(v[i][1] - v[i - 1][1]);
	}
	cout << ans << '\n';
}