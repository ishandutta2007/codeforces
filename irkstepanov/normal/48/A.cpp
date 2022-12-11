#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool win(const string& a, const string& b) {
    if (a == "rock") {
        return b == "scissors";
    } else if (a == "scissors") {
        return b == "paper";
    } else {
        return b == "rock";
    }
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s[3];
    for (int i = 0; i < 3; ++i) {
        cin >> s[i];
    }

    char ans[3] = {'F', 'M', 'S'};

    for (int i = 0; i < 3; ++i) {
        bool ok = true;
        for (int j = 0; j < 3; ++j) {
            if (i == j) {
                continue;
            }
            if (!win(s[i], s[j])) {
                ok = false;
            }
        }
        if (ok) {
            cout << ans[i] << "\n";
            return 0;
        }
    }

    cout << "?\n";

}