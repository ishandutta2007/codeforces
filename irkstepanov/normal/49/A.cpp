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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    char c;
    while (cin >> s) {
        for (int i = 0; i < sz(s); ++i) {
            if (isalpha(s[i])) {
                c = s[i];
            }
        }
    }

    if (c >= 'A' && c <= 'Z') {
        c = char(c - 'A' + 'a');
    }
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
}