#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int nmax = 200;

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
        int x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) {
            cout << "0\n";
            continue;
        }
        int z = x * x + y * y;
        bool ok = false;
        for (int r = 0; r <= nmax; ++r) {
            if (r * r == z) {
                ok = true;
                break;
            }
        }
        cout << (ok ? 1 : 2) << "\n";
    }

}