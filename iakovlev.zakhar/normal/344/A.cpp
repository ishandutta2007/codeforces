#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll MOD998 = 998244353;

typedef unsigned int uint;
typedef unsigned long long ull;


int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, ans;
	ans = 1;
	cin >> n;
	vector<string> s;
	for (int i = 0; i < n; i++) {
        string s1;
        cin >> s1;
        s.push_back(s1);
	}
	for (int i = 1; i < n; i++) {
        ans += abs(s[i][0] - s[i - 1][0]);
	}
	cout << ans << endl;
	return 0;
}