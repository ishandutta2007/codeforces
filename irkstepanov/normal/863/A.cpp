#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

bool pal(const string& s) {
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] != s[sz(s) - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {

    //ifstream cin("input.txt");
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    string s;
    cin >> s;

    for (int i = 0; i < 20; ++i) {
        string t = "";
        for (int j = 0; j < i; ++j) {
            t += "0";
        }
        t += s;
        if (pal(t)) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

}