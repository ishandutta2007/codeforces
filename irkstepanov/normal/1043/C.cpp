#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void rev(string& s, int i) {
    string t = s;
    for (int j = 0; j < i; ++j) {
        t[j] = s[i - j - 1];
    }
    s = t;
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    for (int i = 1; i < sz(s); ++i) {
        if (s[i - 1] == s[i]) {
            cout << "0 ";
            continue;
        }
        cout << "1 ";
        rev(s, i);
        //reverse(s.begin(), s.begin() + i - 1);
    }
    if (s[0] == 'b') {
        cout << "1\n";
    } else {
        cout << "0\n";
    }

}