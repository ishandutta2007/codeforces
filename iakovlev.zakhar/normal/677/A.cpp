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
	int n, h, ans;
	cin >> n >> h;
	ans = n;
	vector<int> s;
	for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.push_back(x);
	}
	for (int i = 0; i < n; i++) {
        ans += (s[i] > h);
        cerr << s[i] << ' ' << h << ' ' << (s[i] > h) << ' ' << ans << endl;
	}
	cout << ans << endl;
	return 0;
}