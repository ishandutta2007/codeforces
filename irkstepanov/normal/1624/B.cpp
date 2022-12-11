#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int inf = 1e9 + 10;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        ll a, b, c;
        cin >> a >> b >> c;
        bool ok = false;

        // fix a
        ll d = c - b;
        ll newa = b - d;
        if (newa > 0 && newa % a == 0) {
            ok = true;
        }

        // fix b
        d = (c - a) / 2;
        ll newb = a + d;
        if ((c - a) % 2 == 0 && newb > 0 && newb % b == 0) {
            ok = true;
        }

        // fix c
        d = b - a;
        ll newc = b + d;
        if (newc > 0 && newc % c == 0) {
            ok = true;
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }

}