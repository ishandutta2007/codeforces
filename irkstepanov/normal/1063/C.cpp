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

const int inf = 1e9 + 1;

char get(int x) {
    cout << x << " 0" << endl;
    string s;
    cin >> s;
    if (s[0] == 'w') {
        return 'w';
    } else {
        return 'b';
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int lf = 0, rg = inf;
    char c1 = get(0);
    
    --n;
    char c2;
    if (c1 == 'w') {
        c2 = 'b';
    } else {
        c2 = 'w';
    }

    while (n--) {
        int md = (lf + rg) >> 1;
        char c = get(md);
        if (c == c1) {
            lf = md;
        } else {
            rg = md;
        }
    }

    if (lf + 1 != rg) {
        cout << lf + 1 << " " << 0 << " " << lf + 1 << " " << 1 << endl;
        return 0;
    }
    cout << lf + 1 << " " << 1 << " " << lf + 2 << " " << 3 << endl;
    
}