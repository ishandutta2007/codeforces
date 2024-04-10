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
	int n;
	cin >> n;
	vector<string> s;
	for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        s.push_back(x);
	}
	int f = 1;
	for (int i = 0; i < n; i++) {
        if (s[i][0] == 'O' && s[i][1] == 'O') {
            s[i] = "++" + s[i].substr(2);
            f--;
            break;
        }
        if (s[i][3] == 'O' && s[i][4] == 'O') {
            s[i] =  s[i].substr(0, 3) + "++";
            f--;
            break;
        }
	}
	if (f) {
        println("NO");
	} else {
        println("YES");
        for (int i = 0; i < n; i++) {
            println(s[i]);
        }
	}
	return 0;
}