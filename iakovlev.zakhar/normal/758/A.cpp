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
	int n;
	cin >> n;
	int sum = 0;
	int mx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        mx = max(x, mx);
    }
	cout << n * mx - sum << endl;
	return 0;
}