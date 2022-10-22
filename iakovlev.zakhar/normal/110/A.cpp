#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())
#define print(x) cout << x
#define println(x) cout << x << endl

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll MOD998 = 998244353;

typedef unsigned int uint;
typedef unsigned long long ull;


int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
    cin >> s;
    int c = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '4' || s[i] == '7') {
            c++;
        }
    }
    if (c == 4 || c == 7) {
        cout << "YES";
    } else {
        cout << "NO";
    }
	return 0;
}