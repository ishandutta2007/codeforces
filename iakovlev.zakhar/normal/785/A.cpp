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
	ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s[0] == 'T') {
            ans += 4;
        } else if (s[0] == 'C') {
            ans += 6;
        } else if (s[0] == 'O') {
            ans += 8;
        } else if (s[0] == 'D') {
            ans += 12;
        } else {
            ans += 20;
        }
	}
	cout << ans << endl;
	return 0;
}